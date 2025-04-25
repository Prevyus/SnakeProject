// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/PointLight.h"
#include "GameFramework/Pawn.h"
#include "MyMacros.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SnakePlayer.generated.h"

UCLASS()
class SNAKEGAME_API ASnakePlayer : public APawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	ASnakePlayer();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere)
	class UFloatingPawnMovement* Movement;
	
	// Functions
	void FreeMove(const struct FInputActionValue& ActionValue);
	void Move();
	void ChangeDirection(const struct FInputActionValue& ActionValue);
	void Rotate(char direction);
	void FreeRotate(const struct FInputActionValue& ActionValue);

	void UpdateTail();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ASpawnableSphere> SphereClass;

	UPROPERTY()
	TArray<ASpawnableSphere*> Tail;

	UFUNCTION()
	void SpawnSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	// Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float dirChangeDelay = .5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed = 360.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveScale = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotateScale = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxJumpCount = 1;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> Sphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UPointLightComponent* Light;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	//Variables
	int32 JumpCount = 0;
	char pastDir = ' ';
	float dirChangeDelayTimer = 0;
	FRotator TargetRotation;
	
};
