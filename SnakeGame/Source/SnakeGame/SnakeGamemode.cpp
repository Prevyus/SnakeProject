#include "SnakeGamemode.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.h"
#include "Apple.h"
#include "SnakeAIController.h"
#include "Blueprint/UserWidget.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

void ASnakeGamemode::BeginPlay()
{
	Super::BeginPlay();
	
	GameStateManager = GetWorld()->SpawnActor<AGameStateManager>();
	if (GameStateManager)
	{
		GameStateManager->SetGameState(EGameState::MainMenu);
	}

	// GameStateManager->SetGameState(EGameState::Game); to switch state to game
	// GameStateManager->SetGameState(EGameState::Outro); to switch state to outro

	// posses player
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	TArray<AActor*> FoundSnakes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), FoundSnakes);

	if (FoundSnakes.Num() > 0)
	{
		PC->Possess(Cast<APawn>(FoundSnakes[0]));
	}

	// spawn and possess the ai snek
	if (SnakePawnClass && SnakeAIControllerClass)
	{
		FVector SpawnLocation = FVector(10.f, 1.f, 10.f);
		FRotator SpawnRotation = FRotator::ZeroRotator;

		ASnakePlayer* AISnake = GetWorld()->SpawnActor<ASnakePlayer>(SnakePawnClass, SpawnLocation, SpawnRotation);
		ASnakeAIController* AIController = GetWorld()->SpawnActor<ASnakeAIController>(SnakeAIControllerClass);

		if (AISnake && AIController)
		{
			AIController->Possess(AISnake);
		}
	}

	GetWorld()->GetTimerManager().SetTimer(AppleSpawnTimer, this, &ASnakeGamemode::SpawnApple, AppleSpawnRate, true);

	GenerateLevelGeometry(1);
	
}

ASnakeGamemode::ASnakeGamemode()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshFinder(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshFinder.Succeeded())
	{
		CubeMesh = CubeMeshFinder.Object;
	}
}

void ASnakeGamemode::ClearLevelGeometry()
{
	for (AActor* A : SpawnedGeometry)
	{
		if (IsValid(A))
		{
			A->Destroy();
		}
	}
	SpawnedGeometry.Empty();
}

void ASnakeGamemode::GenerateLevelGeometry(int32 Level)
{
	if (!GetWorld()) return;

	if (!CubeMesh)
	{
		CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
		if (!CubeMesh)
		{
			UE_LOG(LogTemp, Error, TEXT("[GenerateLevelGeometry] Could not load /Engine/BasicShapes/Cube.Cube"));
			return;
		}
	}

	Level = FMath::Clamp(Level, 1, 3);
	CurrentLevel = Level;
	
	ClearLevelGeometry();

	float Shrink = 1.f;
	switch (Level)
	{
		case 1: Shrink = 1.00f; break;
		case 2: Shrink = 0.5f; break;
		case 3: Shrink = 0.25f; break;
	}

	const float HalfX = BaseHalfExtentX * Shrink;
	const float HalfY = BaseHalfExtentY * Shrink;

	auto SpawnCube = [&](const FVector& Location, const FVector& Scale, const FRotator& Rot = FRotator::ZeroRotator) -> AStaticMeshActor*
	{
		FActorSpawnParameters Params;
		AStaticMeshActor* S = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), Location, Rot, Params);
		if (!S) return nullptr;

		UStaticMeshComponent* MC = S->GetStaticMeshComponent();
		MC->SetStaticMesh(CubeMesh);
		MC->SetMobility(EComponentMobility::Static);
		MC->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		MC->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);

		S->SetActorScale3D(Scale);
		S->SetActorLocation(Location);
		S->SetActorEnableCollision(true);

		SpawnedGeometry.Add(S);
		return S;
	};

	const float Unit = 100.f;
	const float WallThkS = WallThickness / Unit; 
	const float FloorThkS = WallThkS;
	const float HeightS   = CeilingHeight / Unit;

	const float SpanXS = (HalfX * 2.f + WallThickness * 2.f) / Unit;
	const float SpanYS = (HalfY * 2.f + WallThickness * 2.f) / Unit;

	{
		const FVector Loc(0.f, 0.f, -CeilingHeight * 0.5f);
		const FVector Scl((HalfX * 2.f) / Unit, (HalfY * 2.f) / Unit, FloorThkS);
		SpawnCube(Loc, Scl);
	}

	{
		const FVector Loc(0.f, 0.f, +CeilingHeight * 0.5f);
		const FVector Scl((HalfX * 2.f) / Unit, (HalfY * 2.f) / Unit, FloorThkS);
		SpawnCube(Loc, Scl);
	}

	{
		const FVector Loc(-(HalfX + WallThickness * 0.5f), 0.f, 0.f);
		const FVector Scl(WallThkS, SpanYS, HeightS);
		SpawnCube(Loc, Scl);
	}

	{
		const FVector Loc(+(HalfX + WallThickness * 0.5f), 0.f, 0.f);
		const FVector Scl(WallThkS, SpanYS, HeightS);
		SpawnCube(Loc, Scl);
	}

	{
		const FVector Loc(0.f, -(HalfY + WallThickness * 0.5f), 0.f);
		const FVector Scl(SpanXS, WallThkS, HeightS);
		SpawnCube(Loc, Scl);
	}

	{
		const FVector Loc(0.f, +(HalfY + WallThickness * 0.5f), 0.f);
		const FVector Scl(SpanXS, WallThkS, HeightS);
		SpawnCube(Loc, Scl);
	}
}

void ASnakeGamemode::ShowWidget(TSubclassOf<UUserWidget> WidgetClass)
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	if (WidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ASnakeGamemode::SpawnApple()
{	if (!AppleClass) return;

	if (!GameStateManager || GameStateManager->CurrentState != EGameState::Game) return;

	float Shrink = 1.f;
	switch (CurrentLevel)
	{
	case 1: Shrink = 1.00f; break;
	case 2: Shrink = 0.5f; break;
	case 3: Shrink = 0.25f; break;
	}

	const float HalfX = BaseHalfExtentX * Shrink;
	const float HalfY = BaseHalfExtentY * Shrink;
	
	FVector SpawnLocation = FVector(
		FMath::RandRange(-HalfX, HalfX),
		FMath::RandRange(-HalfX, HalfX),
		FMath::RandRange(-HalfY, HalfY)
	);
	GetWorld()->SpawnActor<AApple>(AppleClass, SpawnLocation, FRotator::ZeroRotator);
}