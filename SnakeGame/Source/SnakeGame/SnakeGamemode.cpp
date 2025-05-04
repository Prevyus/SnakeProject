#include "SnakeGamemode.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.h"
#include "SnakeAIController.h"

void ASnakeGamemode::BeginPlay()
{
	Super::BeginPlay();
	
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
}
