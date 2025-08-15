#include "SnakeGamemode.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.h"
#include "Apple.h"
#include "ScoresDisplay.h"
#include "Math/Rotator.h"
#include "SnakeAIController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "OutroScoreDisplay.h"  
#include "GeometryCollection/GeometryCollectionComponent.h"

void ASnakeGamemode::BeginPlay()
{
	Super::BeginPlay();
	
	if (InGameHUDClass)
	{
		InGameHUD = CreateWidget<UScoresDisplay>(GetWorld(), InGameHUDClass);
	}
	
	GameStateManager = GetWorld()->SpawnActor<AGameStateManager>();

	SetSnakesTickEnabled(false);
	ShowInGameHUD(false);
	StopLevelTimer();
	ShowWidget(MainMenuWidgetClass);

	GetWorldTimerManager().SetTimer(ToGameTimer, [this]()
	{
		SetGameState(EGameFlowState::Game);
		CurrentLevel = 1;
		GenerateLevelGeometry(CurrentLevel);
		StartLevelTimer(30);

		GetWorldTimerManager().SetTimer(Level2Timer, [this]()
		{
			CurrentLevel = 2;
			GenerateLevelGeometry(CurrentLevel);
			TArray<AActor*> Snakes;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), Snakes);
			for (AActor* Snake : Snakes)
			{
				if (Snake)
				{
					Snake->SetActorLocation(FVector::ZeroVector);
				}
			}
			StartLevelTimer(30);

			GetWorldTimerManager().SetTimer(Level3Timer, [this]()
			{
				CurrentLevel = 3;
				GenerateLevelGeometry(CurrentLevel);
				TArray<AActor*> Snakes;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), Snakes);
				for (AActor* Snake : Snakes)
				{
					if (Snake)
					{
						Snake->SetActorLocation(FVector::ZeroVector);
					}
				}
				StartLevelTimer(30);

				GetWorldTimerManager().SetTimer(ToOutroTimer, [this]()
				{
					SetGameState(EGameFlowState::Outro);

					GetWorldTimerManager().SetTimer(QuitTimer, [this]()
					{
						UKismetSystemLibrary::QuitGame(
							this,
							UGameplayStatics::GetPlayerController(this, 0),
							EQuitPreference::Quit,false
						);
					}, 10.0f, false);

				}, 30.0f, false);

			}, 30.0f, false);

		}, 30.0f, false);

	}, 3.0f, false);

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	TArray<AActor*> FoundSnakes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), FoundSnakes);

	if (FoundSnakes.Num() > 0)
	{
		PC->Possess(Cast<APawn>(FoundSnakes[0]));
	}

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

	GenerateLevelGeometry(CurrentLevel);
	
}
void ASnakeGamemode::StartLevelTimer(int32 DurationSeconds)
{
	RemainingSeconds = FMath::Max(0, DurationSeconds);
	if (InGameHUD) InGameHUD->SetTimeLeft(RemainingSeconds);

	GetWorldTimerManager().ClearTimer(LevelTickHandle);
	GetWorldTimerManager().SetTimer(LevelTickHandle, this, &ASnakeGamemode::OnLevelTimerTick, 1.0f, true);
}

void ASnakeGamemode::StopLevelTimer()
{
	GetWorldTimerManager().ClearTimer(LevelTickHandle);
}

void ASnakeGamemode::OnLevelTimerTick()
{
	RemainingSeconds = FMath::Max(0, RemainingSeconds - 1);
	if (InGameHUD) InGameHUD->SetTimeLeft(RemainingSeconds);

	if (RemainingSeconds <= 0)
	{
		// Time’s up for this level — stop and trigger your “advance level / decide winner” logic
		StopLevelTimer();

		// Example hook you already have elsewhere:
		// AdvanceLevelOrEndMatch();
	}
}

void ASnakeGamemode::ShowInGameHUD(bool bShow)
{
	if (!InGameHUD) return;

	if (bShow)
	{
		if (!InGameHUD->IsInViewport())
		{
			InGameHUD->AddToViewport(0);
		}
	}
	else
	{
		if (InGameHUD->IsInViewport())
		{
			InGameHUD->RemoveFromParent();
		}
	}
}

void ASnakeGamemode::SetGameState(EGameFlowState NewState)
{
	if (CurrentState == NewState) return;
	CurrentState = NewState;

	switch (CurrentState)
	{
	case EGameFlowState::Game:
		SetSnakesTickEnabled(true);

		ShowWidget(nullptr);
		if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
		{
			PC->SetShowMouseCursor(false);
			FInputModeGameOnly IM; PC->SetInputMode(IM);
		}

		ShowInGameHUD(true);
		StartLevelTimer(6);
		break;

	case EGameFlowState::Outro:
		SetSnakesTickEnabled(false);
		ShowInGameHUD(false);
		StopLevelTimer();
		ShowWidget(OutroWidgetClass);

		{
		ASnakePlayer* P1 = Cast<ASnakePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
		int32 S1 = (P1 ? P1->Tail.Num() : 0);

		ASnakePlayer* P2 = nullptr;
		{
			TArray<AActor*> Snakes;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), Snakes);
			for (AActor* A : Snakes)
			{
				ASnakePlayer* S = Cast<ASnakePlayer>(A);
				if (S && S != P1) { P2 = S; break; }
			}
		}
		int32 S2 = (P2 ? P2->Tail.Num() : 0);

		FString Winner;
		if (S1 > S2)       Winner = TEXT("Winner: Player 1");
		else if (S2 > S1)  Winner = TEXT("Winner: Player 2");
		else               Winner = TEXT("Result: Tie");

		FString Text = FString::Printf(TEXT("Player 1: %d\nPlayer 2: %d\n%s"), S1, S2, *Winner);

		if (CurrentWidget)
		{
			if (UOutroScoreDisplay* Outro = Cast<UOutroScoreDisplay>(CurrentWidget))
			{
				Outro->SetText(Text);
			}
		}
		}
		break;
	}
}

void ASnakeGamemode::SetSnakesTickEnabled(bool bEnable)
{
	TArray<AActor*> Snakes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), Snakes);
	for (AActor* A : Snakes)
	{
		if (A) A->SetActorTickEnabled(bEnable);
	}

	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		if (APlayerController* PC = It->Get())
		{
			PC->SetIgnoreMoveInput(!bEnable);
			PC->SetIgnoreLookInput(!bEnable);
		}
	}
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

	Level = FMath::Clamp(Level, 1, 3);
	CurrentLevel = Level;

	ClearLevelGeometry();

	float Shrink = 1.f;
	switch (Level)
	{
	case 1: Shrink = 1.00f; break;
	case 2: Shrink = 0.50f; break;
	case 3: Shrink = 0.25f; break;
	}

	const float HalfX = BaseHalfExtentX * Shrink;
	const float HalfY = BaseHalfExtentY * Shrink;

	const float EffectiveHeight = CeilingHeight * Shrink;
	auto SpawnWallBP = [&](const FVector& Location, const FVector& Scale, const FRotator& Rot) -> AActor*
	{
		if (!WallBlueprintClass) { UE_LOG(LogTemp, Error, TEXT("[GenerateLevelGeometry] WallBlueprintClass not set!")); return nullptr; }
		const FTransform T(Rot, Location, Scale);
		AActor* Wall = GetWorld()->SpawnActorDeferred<AActor>(WallBlueprintClass, T);
		if (!Wall) return nullptr;
		Wall->FinishSpawning(T);
		SpawnedGeometry.Add(Wall);
		return Wall;
	};

	const float Unit      = 100.f;
	const float WallThkS  = WallThickness / Unit;
	const float FloorThkS = WallThkS; 
	const float HeightS   = EffectiveHeight / Unit;

	const float SpanXS = (HalfX * 2.f + WallThickness * 2.f) / Unit;
	const float SpanYS = (HalfY * 2.f + WallThickness * 2.f) / Unit;

	{
		const FVector Loc(0.f, 0.f, -EffectiveHeight * 0.5f);
		const FVector Scl((HalfX * 2.f) / Unit, (HalfY * 2.f) / Unit, FloorThkS);
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}

	{
		const FVector Loc(0.f, 0.f, +EffectiveHeight * 0.5f);
		const FVector Scl((HalfX * 2.f) / Unit, (HalfY * 2.f) / Unit, FloorThkS);
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}

	{
		const FVector Loc(-(HalfX + WallThickness * 0.5f), 0.f, 0.f);
		const FVector Scl(WallThkS, SpanYS, HeightS); 
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}

	{
		const FVector Loc(+(HalfX + WallThickness * 0.5f), 0.f, 0.f);
		const FVector Scl(WallThkS, SpanYS, HeightS);
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}

	{
		const FVector Loc(0.f, -(HalfY + WallThickness * 0.5f), 0.f);
		const FVector Scl(SpanXS, WallThkS, HeightS);
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}

	{
		const FVector Loc(0.f, +(HalfY + WallThickness * 0.5f), 0.f);
		const FVector Scl(SpanXS, WallThkS, HeightS);
		SpawnWallBP(Loc, Scl, FRotator::ZeroRotator);
	}
}


void ASnakeGamemode::ShowWidget(TSubclassOf<UUserWidget> WidgetClass)
{
	UE_LOG(LogTemp, Warning, TEXT("ShowWidget: %s"),
		WidgetClass ? *WidgetClass->GetName() : TEXT("NULL"));
	
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromParent();
		CurrentWidget = nullptr;
	}

	if (!WidgetClass) return;

	CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	if (!CurrentWidget) return;

	CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	CurrentWidget->AddToViewport(1000); // <-- ensure on top

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetShowMouseCursor(true);
		FInputModeUIOnly IM; IM.SetWidgetToFocus(CurrentWidget->TakeWidget());
		PC->SetInputMode(IM);
	}
}

void ASnakeGamemode::SpawnApple()
{	if (!AppleClass) return;

	if (const ASnakeGamemode* GM = Cast<ASnakeGamemode>(UGameplayStatics::GetGameMode(this)))
	{
		if (!GM->IsGameplayActive()) return;
	}

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