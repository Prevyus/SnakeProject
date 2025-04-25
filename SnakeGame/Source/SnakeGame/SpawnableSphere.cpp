#include "SpawnableSphere.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

ASpawnableSphere::ASpawnableSphere()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	RootComponent = SphereCollider;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SphereMesh->SetupAttachment(SphereCollider);
}
