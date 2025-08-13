// Apple.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Apple.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAppleEaten, AApple*, Apple);

UCLASS()
class SNAKEGAME_API AApple : public AActor
{
	GENERATED_BODY()
	
public:	
	AApple();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAppleEaten OnAppleEaten;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleEaten(AApple* Apple);
	
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;
};
