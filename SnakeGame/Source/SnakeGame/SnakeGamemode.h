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

UCLASS()
class SNAKEGAME_API ASnakeGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	ASnakeGamemode();

	UFUNCTION(BlueprintCallable, Category="Level|Geometry")
	void GenerateLevelGeometry(int32 Level);

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
	TSubclassOf<UUserWidget> GameWidgetClass;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> OutroWidgetClass;

	UPROPERTY()
	UUserWidget* CurrentWidget;

	UFUNCTION(BlueprintCallable)
	void ShowWidget(TSubclassOf<UUserWidget> WidgetClass);

protected:
	
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
};
