#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameStateManager.h"
#include "Blueprint/UserWidget.h"
#include "SnakeGamemode.generated.h"

// Forward declarations
class ASnakePlayer;
class ASnakeAIController;
class AApple;
class UUserWidget;

UCLASS()
class SNAKEGAME_API ASnakeGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	/** Player and AI snake setup */
	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<ASnakePlayer> SnakePawnClass;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<ASnakeAIController> SnakeAIControllerClass;

	/** Apple spawning */
	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<AApple> AppleClass;

	FTimerHandle AppleSpawnTimer;
	void SpawnApple();

	/** Reference to the game state manager */
	UPROPERTY()
	AGameStateManager* GameStateManager;

	/** UI Widgets for each state */
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> GameWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> OutroWidgetClass;

	/** Currently active widget */
	UPROPERTY()
	UUserWidget* CurrentWidget;

	/** Function to show a widget */
	UFUNCTION(BlueprintCallable)
	void ShowWidget(TSubclassOf<UUserWidget> WidgetClass);
};
