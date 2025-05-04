#include "GameStateManager.h"

AGameStateManager::AGameStateManager()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentState = EGameState::MainMenu;
}

void AGameStateManager::SetGameState(EGameState NewState)
{
	CurrentState = NewState;

	// Optional: Do something based on state, like logging
	UE_LOG(LogTemp, Warning, TEXT("Game State changed to: %d"), (uint8)CurrentState);
}
