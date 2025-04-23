// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/PointLight.h"
#include "GameFramework/Pawn.h"
#include "SnakePlayer.generated.h"

UCLASS()
class SNAKEGAME_API ASnakePlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	UPointLightComponent* Light;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
