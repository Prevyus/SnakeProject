// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGamemode.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASnakeGamemode : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<class ASnakePlayer> SnakePawnClass;

	UPROPERTY(EditDefaultsOnly, Category = "Snake")
	TSubclassOf<class ASnakeAIController> SnakeAIControllerClass;

	
};
