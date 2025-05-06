#include "GameStateManager.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeGamemode.h"
#include "Blueprint/UserWidget.h"

AGameStateManager::AGameStateManager()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentState = EGameState::MainMenu;
}

void AGameStateManager::SetGameState(EGameState NewState)
{
	CurrentState = NewState;
	UE_LOG(LogTemp, Warning, TEXT("Game State changed to: %d"), (uint8)CurrentState);

	ASnakeGamemode* GameMode = Cast<ASnakeGamemode>(UGameplayStatics::GetGameMode(this));
	if (!GameMode) return;

	// Optional: trigger UI switch or game logic
	/*
	switch (NewState)
	{
	case EGameState::MainMenu:
		GameMode->ShowWidget(GameMode->MainMenuWidgetClass);
		break;
	case EGameState::Game:
		GameMode->ShowWidget(GameMode->GameWidgetClass);
		break;
	case EGameState::Outro:
		GameMode->ShowWidget(GameMode->OutroWidgetClass);
		break;
	}
	*/
}
