#include "SnakeGamemode.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.h"
#include "Apple.h"
#include "SnakeAIController.h"
#include "Blueprint/UserWidget.h"

void ASnakeGamemode::BeginPlay()
{
	Super::BeginPlay();
	
	GameStateManager = GetWorld()->SpawnActor<AGameStateManager>();

	//ShowWidget(MainMenuWidgetClass);
	GameStateManager->SetGameState(EGameState::MainMenu);
	
	// Possess the placed player snake in the level
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	TArray<AActor*> FoundSnakes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASnakePlayer::StaticClass(), FoundSnakes);

	if (FoundSnakes.Num() > 0)
	{
		PC->Possess(Cast<APawn>(FoundSnakes[0]));
	}

	// Spawn and possess the AI snake
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

	GetWorld()->GetTimerManager().SetTimer(AppleSpawnTimer, this, &ASnakeGamemode::SpawnApple, 2.5f, true);
}

// void ASnakeGamemode::ShowWidget(TSubclassOf<UUserWidget> WidgetClass)
// {
// 	if (CurrentWidget)
// 	{
// 		CurrentWidget->RemoveFromParent();
// 		CurrentWidget = nullptr;
// 	}
//
// 	if (WidgetClass)
// 	{
// 		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
// 		if (CurrentWidget)
// 		{
// 			CurrentWidget->AddToViewport();
// 		}
// 	}
// }

void ASnakeGamemode::SpawnApple()
{
	if (!AppleClass) return;

	FVector SpawnLocation = FVector(
		FMath::RandRange(-3000, 3000),
		FMath::RandRange(-3000, 3000),
		FMath::RandRange(0, 1000)
	);
	GetWorld()->SpawnActor<AApple>(AppleClass, SpawnLocation, FRotator::ZeroRotator);
}