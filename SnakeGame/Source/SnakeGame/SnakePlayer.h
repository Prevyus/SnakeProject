// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/PointLight.h"
#include "GameFramework/Pawn.h"
#include "MyMacros.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameStateManager.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.generated.h"

class UBoxComponent;

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
	void Move();
	void ChangeDirection(const struct FInputActionValue& ActionValue);
	void Rotate(char direction);
	char UpdateWorldDirection (char currDir, char rotation);
	void Kill();

	void TestChangeState();

	void UpdateTail();


	float dirChangeDelayTimer = 0;
	char horWorldDir = 'X';
	char verWorldDir = 'm';
	bool binaryTurned = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isPlayer = false;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ASpawnableSphere> SphereClass;

	UPROPERTY()
	TArray<ASpawnableSphere*> Tail;

	UFUNCTION()
	void SpawnSpheres();
	UFUNCTION()
	void SpawnSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float dirChangeDelay = .5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed = 360.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveScale = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotateScale = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int GrowAmount = 10;

private:

	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> Sphere;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> Collider;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UPointLightComponent* Light;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent;
	
	//Variables
	int32 JumpCount = 0;
	char pastDir = ' ';
	FRotator TargetRotation;
	int collisions = 0;
	
};
