#include "SnakeAIController.h"
#include "Apple.h"
#include "Kismet/GameplayStatics.h"
#include "SnakePlayer.h"

void ASnakeAIController::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void ASnakeAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ControlledSnake = Cast<ASnakePlayer>(InPawn);
	UE_LOG(LogTemp, Warning, TEXT("Snake AI Possessed: %s"), *InPawn->GetName());
}

int test = 0;
void ASnakeAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ControlledSnake)
	{
		MakeDecision();
	}
}

//int testing = 0;
//bool verticalTurn = false;
void ASnakeAIController::MakeDecision()
{
	if (!ControlledSnake) return;
	if (ControlledSnake->dirChangeDelayTimer > 0) return;

	TArray<AActor*> Apples;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AApple::StaticClass(), Apples);

	if (Apples.Num() == 0) return;

	FVector SnakeLocation = ControlledSnake->GetActorLocation();
	AActor* ClosestApple = nullptr;
	float MinDist = FLT_MAX;

	for (AActor* Apple : Apples)
	{
		float Dist = FVector::Dist(SnakeLocation, Apple->GetActorLocation());
		if (Dist < MinDist)
		{
			MinDist = Dist;
			ClosestApple = Apple;
		}
	}

	if (ClosestApple)
	{
		targetPos = ClosestApple->GetActorLocation();
	}
	
	//verticalTurn = !verticalTurn;
	
	FVector DirectionToTarget = targetPos - SnakeLocation;

	float DeltaX = DirectionToTarget.X;
	float DeltaY = DirectionToTarget.Y;
	float DeltaZ = DirectionToTarget.Z;

	
	//UE_LOG(LogTemp, Warning, TEXT("x %f, y %f, z %f"), DeltaX,DeltaY,DeltaZ);
	//UE_LOG(LogTemp, Warning, TEXT("Z %f"), DeltaZ);

	if (!(FMath::Abs(DeltaX) < 300 && FMath::Abs(DeltaY) < 300))//FMath::Abs(DeltaZ) < 100 || verticalTurn)
	{
		//UE_LOG(LogTemp, Warning, TEXT("hor %d"), testing);
		//testing++;
		
		//UE_LOG(LogTemp, Warning, TEXT("dir %c"), (TCHAR)ControlledSnake->verWorldDir);
		if (ControlledSnake->verWorldDir == 'u')
		{
			ControlledSnake->Rotate('d');
			return;
		}
		if (ControlledSnake->verWorldDir == 'd')
		{
			ControlledSnake->Rotate('u');
			return;
		}
		
		if (FMath::Abs(DeltaX) > FMath::Abs(DeltaY))
		{
			if (DeltaX > 0)
			{
				//UE_LOG(LogTemp, Warning, TEXT("X+ | %c"), (TCHAR)ControlledSnake->worldDir);
				if (ControlledSnake->horWorldDir == 'x' || ControlledSnake->horWorldDir == 'y')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->horWorldDir == 'Y')
				{
					ControlledSnake->Rotate('l');
				}
			}
			else
			{
				//UE_LOG(LogTemp, Warning, TEXT("x- | %c"), (TCHAR)ControlledSnake->worldDir);
				if (ControlledSnake->horWorldDir == 'X' || ControlledSnake->horWorldDir == 'Y')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->horWorldDir == 'y')
				{
					ControlledSnake->Rotate('l');
				}
			}
		}
		else
		{
			if (DeltaY > 0)
			{
				//UE_LOG(LogTemp, Warning, TEXT("Y+ | %c"), (TCHAR)ControlledSnake->worldDir);
				if (ControlledSnake->horWorldDir == 'y' || ControlledSnake->horWorldDir == 'X')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->horWorldDir == 'x')
				{
					ControlledSnake->Rotate('l');
				}
			}
			else
			{
				//UE_LOG(LogTemp, Warning, TEXT("y- | %c"), (TCHAR)ControlledSnake->worldDir);
				if (ControlledSnake->horWorldDir == 'Y' || ControlledSnake->horWorldDir == 'x')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->horWorldDir == 'X')
				{
					ControlledSnake->Rotate('l');
				}
			}
		}
	}
	else// if (FMath::Abs(DeltaZ) <= 400)
	{
		//UE_LOG(LogTemp, Warning, TEXT("ver %d"), testing);
		//testing++;
		if (DeltaZ != 0)
		{
			if (DeltaZ > 0)
			{
				ControlledSnake->Rotate('u');  // moving in +X
			}
			else
			{
				ControlledSnake->Rotate('d');  // moving in -X
			}
		}
	}
}
