#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameStateManager.h"
#include "Blueprint/UserWidget.h"
#include "SnakeGamemode.generated.h"

class ASnakePlayer;
class ASnakeAIController;
class AApple;
class UUserWidget;

UENUM(BlueprintType)
enum class EGameFlowState : uint8 { MainMenu, Game, Outro };

class UScoresDisplay;

UCLASS()
class SNAKEGAME_API ASnakeGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	ASnakeGamemode();
	
	// Call this when you enter Game state
	UFUNCTION(BlueprintCallable)
	void StartLevelTimer(int32 DurationSeconds = 60);

	// If you already have state gating, call StopLevelTimer() when leaving Game
	UFUNCTION(BlueprintCallable)
	void StopLevelTimer();

	// Use this to show the HUD when state is Game
	UFUNCTION(BlueprintCallable)
	void ShowInGameHUD(bool bShow);
	
	void SetGameState(EGameFlowState NewState);
	bool IsGameplayActive() const { return CurrentState == EGameFlowState::Game; }

	UFUNCTION(BlueprintCallable, Category="Level|Geometry")
	void GenerateLevelGeometry(int32 Level);

	UPROPERTY(EditDefaultsOnly, Category="Level|Geometry")
	TSubclassOf<AActor> WallBlueprintClass;

	UPROPERTY(EditDefaultsOnly)
	int32 CurrentLevel = 1;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<ASnakePlayer> SnakePawnClass;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<ASnakeAIController> SnakeAIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<AApple> AppleClass;

	FTimerHandle AppleSpawnTimer;
	void SpawnApple();

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	float AppleSpawnRate = 1;

	UPROPERTY()
	AGameStateManager* GameStateManager;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> OutroWidgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;

	UFUNCTION(BlueprintCallable)
	void ShowWidget(TSubclassOf<UUserWidget> WidgetClass);

protected:

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UScoresDisplay> InGameHUDClass;
	
	EGameFlowState CurrentState = EGameFlowState::MainMenu;

	FTimerHandle ToGameTimer;
	FTimerHandle ToOutroTimer;
	FTimerHandle QuitTimer;
	FTimerHandle Level2Timer;
	FTimerHandle Level3Timer;

	void SetSnakesTickEnabled(bool bEnable);
	
	void ClearLevelGeometry();

	UPROPERTY(EditDefaultsOnly, Category="Level|Geometry")
	float BaseHalfExtentX = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category="Level|Geometry")
	float BaseHalfExtentY = 3000.f;

	UPROPERTY(EditDefaultsOnly, Category="Level|Geometry")
	float CeilingHeight = 400.f;

	UPROPERTY(EditDefaultsOnly, Category="Level|Geometry")
	float WallThickness = 100.f;

	UPROPERTY()
	TArray<AActor*> SpawnedGeometry;

	UPROPERTY()
	UStaticMesh* CubeMesh = nullptr;

private:
	UPROPERTY() UScoresDisplay* InGameHUD = nullptr;

	FTimerHandle LevelTickHandle;
	int32 RemainingSeconds = 0;

	void OnLevelTimerTick();
};
