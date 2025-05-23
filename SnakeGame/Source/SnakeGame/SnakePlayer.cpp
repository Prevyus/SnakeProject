// Fill out your copyright notice in the Description page of Project Settings.

#include "SnakePlayer.h"
#include "SpawnableSphere.h"
#include "Apple.h"
#include "SnakePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MovieSceneSequenceID.h"
#include "GameStateManager.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeGamemode.h"
#include "Components/PointLightComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"

// Sets default values
ASnakePlayer::ASnakePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Components
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->InitSphereRadius(50);
	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	Collider->InitSphereRadius(50);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("SnakeMesh");
	Light = CreateDefaultSubobject<UPointLightComponent>("Light");
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SpringArm");
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

	//Setup Attachments 
	RootComponent = Sphere;
	Collider->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(RootComponent);
	Light->SetupAttachment(RootComponent);
	SceneComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASnakePlayer::BeginPlay()
{
	Super::BeginPlay();

	AGameStateManager* GameStateManager = Cast<AGameStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameStateManager::StaticClass()));


	if (Collider)
	{
		Collider->OnComponentBeginOverlap.AddDynamic(this, &ASnakePlayer::OnBeginOverlap);
	}

	for(int i = 0; i < 5; i++)
	{
		SpawnSpheres();
	}
}

void ASnakePlayer::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("%d"), collisions);
	collisions++;
	
	if (OtherActor->IsA(AApple::StaticClass()))
	{
		OtherActor->Destroy();
		SpawnSpheres(); // Grow snake
	}
}

// Called every frame
void ASnakePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ASnakeGamemode* GameMode = Cast<ASnakeGamemode>(UGameplayStatics::GetGameMode(this));
	if (!GameMode || !GameMode->GameStateManager) return;
	if (GameMode->GameStateManager->CurrentState != EGameState::Game) return;
	
	if (dirChangeDelayTimer > 0) dirChangeDelayTimer -= DeltaTime;

	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, RotationSpeed);
	SetActorRotation(NewRotation);
	
	Move();
	UpdateTail();
}

void ASnakePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	ASnakePlayerController* FPC = Cast<ASnakePlayerController>(Controller);
	check(EIC && FPC);

	// FREE MOVEMENT
	EIC->BindAction(FPC->MoveAction, ETriggerEvent::Triggered, this, &ASnakePlayer::ChangeDirection);
	//EIC->BindAction(FPC->RotateAction, ETriggerEvent::Triggered, this, &ASnakePlayer::Rotate);
	EIC->BindAction(FPC->SpawnSphereAction, ETriggerEvent::Started, this, &ASnakePlayer::SpawnSpheres);
	
	EIC->BindAction(FPC->ChangeStateAction, ETriggerEvent::Started, this, &ASnakePlayer::TestChangeState);  // Replace Jump with your function


	ULocalPlayer* LocalPlayer = FPC->GetLocalPlayer();
	check(LocalPlayer);
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(FPC->PawnMappingContext, 0);

}

void ASnakePlayer::TestChangeState()
{
	AGameStateManager* GameStateManager = Cast<AGameStateManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameStateManager::StaticClass()));
	if (!GameStateManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameStateManager not found"));
		return;
	}

	EGameState CurrentState = GameStateManager->CurrentState;
	EGameState NewState;

	switch (CurrentState)
	{
	case EGameState::MainMenu:
		NewState = EGameState::Game;
		break;
	case EGameState::Game:
		NewState = EGameState::Outro;
		break;
	case EGameState::Outro:
	default:
		NewState = EGameState::MainMenu;
		break;
	}

	GameStateManager->SetGameState(NewState);

	UE_LOG(LogTemp, Warning, TEXT("Switched to state: %d"), static_cast<uint8>(NewState));
}




void ASnakePlayer::Move()
{
	FVector Input(1,0,0);
	AddMovementInput(GetActorRotation().RotateVector(Input), MoveScale);
}

void SnapTargetYaw(double& value)
{
	TArray<float> ValidYaws = {0.f, 90.f, 180.f, 270.f, -90.f, -180.f, -270.f};

	float CurrentYaw = value;
	float BestYaw = ValidYaws[0];
	float SmallestDifference = FMath::Abs(CurrentYaw - BestYaw);

	for (float ValidYaw : ValidYaws)
	{
		float Difference = FMath::Abs(CurrentYaw - ValidYaw);
		if (Difference < SmallestDifference)
		{
			SmallestDifference = Difference;
			BestYaw = ValidYaw;
		}
	}

	value = BestYaw;
}

void ASnakePlayer::ChangeDirection(const struct FInputActionValue& ActionValue)
{
	if (dirChangeDelayTimer > 0) return;
	
	FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();

	if (Input.X == 1)
	{
		Rotate('u');
	}
	else if (Input.X == -1)
	{
		Rotate('d');
	}
	else if (Input.Y == 1)
	{
		Rotate('r');
	}
	else if (Input.Y == -1)
	{
		Rotate('l');
	}
}

void ASnakePlayer::Rotate(char direction)
{
	if (dirChangeDelayTimer > 0) return;

	dirChangeDelayTimer = dirChangeDelay;
	
	pastDir = direction;

	switch (direction)
	{
	case 'u':
		verWorldDir = UpdateWorldDirection(verWorldDir, 'u');
		TargetRotation.Pitch += 90.0f;
		break;
	case 'd':
		verWorldDir = UpdateWorldDirection(verWorldDir, 'd');
		TargetRotation.Pitch -= 90.0f;
		break;
	case 'r':
		horWorldDir = UpdateWorldDirection(horWorldDir, 'r');
		TargetRotation.Yaw += 90.0f;
		break;
	case 'l':
		horWorldDir = UpdateWorldDirection(horWorldDir, 'l');
		TargetRotation.Yaw -= 90.0f;
		break;
		
	default:
		break;
	}

	binaryTurned = !binaryTurned;
	TargetRotation.Pitch = FMath::ClampAngle(TargetRotation.Pitch, -89.9f, 89.9f);
	TargetRotation.Roll = 0.0f;
}

char ASnakePlayer::UpdateWorldDirection(char currDir, char rotation)
{
	switch (currDir)
	{
	case 'X':
		if (rotation == 'r')
		{
			return 'Y';
		}
		else if (rotation == 'l')
		{
			return 'y';
		}
		else if (rotation == 'u' || rotation == 'd')
		{
			return 'X';
		}
		break;

	case 'x':
		if (rotation == 'r')
		{
			return 'y';
		}
		else if (rotation == 'l')
		{
			return 'Y';
		}
		else if (rotation == 'u' || rotation == 'd')
		{
			return 'x';
		}
		break;

	case 'Y':
		if (rotation == 'r')
		{
			return 'x';
		}
		else if (rotation == 'l')
		{
			return 'X';
		}
		else if (rotation == 'u' || rotation == 'd')
		{
			return 'Y';
		}
		break;

	case 'y':
		if (rotation == 'r')
		{
			return 'X';
		}
		else if (rotation == 'l')
		{
			return 'x';
		}
		else if (rotation == 'u' || rotation == 'd')
		{
			return 'y';
		}
		break;

	case 'u':
		if (rotation == 'u')
		{
			return 'u';
		}
		else if (rotation == 'd')
		{
			return 'm';
		}
		break;

	case 'm':
		if (rotation == 'u')
		{
			return 'u';
		}
		else if (rotation == 'd')
		{
			return 'd';
		}
		break;

	case 'd':
		if (rotation == 'u')
		{
			return 'm';
		}
		else if (rotation == 'd')
		{
			return 'd';
		}
		break;
	}
	return ' ';
}


void ASnakePlayer::SpawnSpheres()
{
	for (int i = 0; i < GrowAmount; i++)
	{
		SpawnSphere();
	}
}

void ASnakePlayer::SpawnSphere()
{
	if (!SphereClass) return;

	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200;
	FRotator SpawnRotation = FRotator::ZeroRotator;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	ASpawnableSphere* NewSphere = GetWorld()->SpawnActor<ASpawnableSphere>(SphereClass, SpawnLocation, SpawnRotation, SpawnParams);

	if (NewSphere)
	{
		//NewSphere->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		Tail.Add(NewSphere);
	}
}

void ASnakePlayer::UpdateTail()
{
	FVector PreviousPosition = GetActorLocation();

	for (int i = 0; i < Tail.Num(); i++)
	{
		if (!Tail[i]) continue;

		FVector Temp = Tail[i]->GetActorLocation();
		Tail[i]->SetActorLocation(PreviousPosition);
		PreviousPosition = Temp;
	}
}

void ASnakePlayer::Kill()
{
	
}
