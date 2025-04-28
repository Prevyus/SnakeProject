// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnableSphere.h"
#include "SnakePlayer.h"
#include "SnakePlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MovieSceneSequenceID.h"
#include "Components/PointLightComponent.h"
#include "EntitySystem/MovieSceneEntitySystemRunner.h"

// Sets default values
ASnakePlayer::ASnakePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Components
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->InitSphereRadius(100);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("SnakeMesh");
	Light = CreateDefaultSubobject<UPointLightComponent>("Light");
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SpringArm");
	if (isPlayer) { Camera = CreateDefaultSubobject<UCameraComponent>("Camera");} 
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");

	//Setup Attachments 
	RootComponent = Sphere;
	Mesh->SetupAttachment(RootComponent);
	Light->SetupAttachment(RootComponent);
	SceneComponent->SetupAttachment(RootComponent);
	if (isPlayer) { Camera->SetupAttachment(SceneComponent); }
}

// Called when the game starts or when spawned
void ASnakePlayer::BeginPlay()
{
	Super::BeginPlay();

	for(int i = 0; i < 5; i++)
	{
		SpawnSpheres();
	}
}

// Called every frame
void ASnakePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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

	ULocalPlayer* LocalPlayer = FPC->GetLocalPlayer();
	check(LocalPlayer);
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(FPC->PawnMappingContext, 0);

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

	dirChangeDelayTimer = dirChangeDelay;
    
	FVector Input = ActionValue.Get<FInputActionValue::Axis3D>();

	if (Input.X == 1)
	{
		pastDir = 'u';
		Rotate(pastDir);
	}
	else if (Input.X == -1)
	{
		pastDir = 'd';
		Rotate(pastDir);
	}
	else if (Input.Y == 1)
	{
		pastDir = 'r';
		Rotate(pastDir);
	}
	else if (Input.Y == -1)
	{
		pastDir = 'l';
		Rotate(pastDir);
	}
}

void ASnakePlayer::Rotate(char direction)
{
	//TargetRotation = GetActorRotation();

	switch (direction)
	{
	case 'u':
		TargetRotation.Pitch += 90.0f;
		break;
	case 'd':
		TargetRotation.Pitch -= 90.0f;
		break;
	case 'r':
		TargetRotation.Yaw += 90.0f;
		break;
	case 'l':
		TargetRotation.Yaw -= 90.0f;
		break;
		
	default:
		break;
	}

	TargetRotation.Pitch = FMath::ClampAngle(TargetRotation.Pitch, -89.9f, 89.9f);
	TargetRotation.Roll = 0.0f;
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



