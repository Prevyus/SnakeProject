// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SnakePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SNAKEGAME_API ASnakePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

	UPROPERTY()
	class UInputMappingContext* PawnMappingContext;

	UPROPERTY()
	class UInputAction* MoveAction;
	
	UPROPERTY()
	class UInputAction* RotateAction;

	UPROPERTY()
	class UInputAction* SpawnSphereAction;
};
