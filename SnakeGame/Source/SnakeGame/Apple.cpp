// Apple.cpp
#include "Apple.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}
