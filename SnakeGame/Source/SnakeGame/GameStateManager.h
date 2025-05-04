#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameStateManager.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	MainMenu,
	Game,
	Outro
};

UCLASS()
class SNAKEGAME_API AGameStateManager : public AActor
{
	GENERATED_BODY()
	
public:
	AGameStateManager();

	UPROPERTY(BlueprintReadOnly)
	EGameState CurrentState;

	UFUNCTION(BlueprintCallable)
	void SetGameState(EGameState NewState);
};
