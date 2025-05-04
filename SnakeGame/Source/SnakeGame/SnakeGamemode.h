// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameStateManager.h"
#include "SnakeGamemode.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASnakeGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<class ASnakePlayer> SnakePawnClass;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<class ASnakeAIController> SnakeAIControllerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AApple> AppleClass;

	FTimerHandle AppleSpawnTimer;

	void SpawnApple();
	
	UPROPERTY()
	AGameStateManager* GameStateManager;

	// Optionally store widget references
	// UPROPERTY(EditAnywhere)
	// TSubclassOf<class UUserWidget> MainMenuWidgetClass;
	//
	// UPROPERTY(EditAnywhere)
	// TSubclassOf<class UUserWidget> GameWidgetClass;
	//
	// UPROPERTY(EditAnywhere)
	// TSubclassOf<class UUserWidget> OutroWidgetClass;
	//
	// UUserWidget* CurrentWidget;
	//
	// void ShowWidget(TSubclassOf<UUserWidget> WidgetClass);
};
