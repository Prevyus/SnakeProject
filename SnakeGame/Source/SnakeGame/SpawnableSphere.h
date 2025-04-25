#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnableSphere.generated.h"

UCLASS()
class SNAKEGAME_API ASpawnableSphere : public AActor
{
	GENERATED_BODY()

public:	
	ASpawnableSphere();

protected:
	UPROPERTY(VisibleAnywhere)
	class USphereComponent* SphereCollider;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SphereMesh;
};
