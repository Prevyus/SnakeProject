// Apple.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Apple.generated.h"

UCLASS()
class SNAKEGAME_API AApple : public AActor
{
	GENERATED_BODY()
	
public:	
	AApple();

protected:
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Mesh;
};
