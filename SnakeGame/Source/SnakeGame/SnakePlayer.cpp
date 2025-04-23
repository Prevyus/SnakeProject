// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePlayer.h"

#include "Components/PointLightComponent.h"
#define debug(msg) UE_LOG(LogTemp, Warning, TEXT(msg))

// Sets default values
ASnakePlayer::ASnakePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("SnakeMesh");
	Light = CreateDefaultSubobject<UPointLightComponent>("LightYagami");

	//Setup Attachments
	SetRootComponent(Mesh);
	Light->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void ASnakePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASnakePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	debug("Tick");
}

// Called to bind functionality to input
void ASnakePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

