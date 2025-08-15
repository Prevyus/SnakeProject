// Apple.cpp
#include "Apple.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AApple::AApple()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void AApple::BeginPlay()
{
	Super::BeginPlay();

	OnAppleEaten.AddDynamic(this, &AApple::HandleEaten);
}

void AApple::HandleEaten(AApple* Apple)
{
	if (EatAppleEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			EatAppleEffect,
			GetActorLocation(),
			GetActorRotation()
		);
	}
	
	Apple->Destroy();
}
