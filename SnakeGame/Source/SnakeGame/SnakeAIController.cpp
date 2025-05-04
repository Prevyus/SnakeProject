#include "SnakeAIController.h"
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

bool verticalTurn = false;
void ASnakeAIController::MakeDecision()
{
	if (!ControlledSnake) return;
	if (ControlledSnake->dirChangeDelayTimer > 0) return;
	verticalTurn = !verticalTurn;
	
	FVector SnakeLocation = ControlledSnake->GetActorLocation();
	FVector DirectionToTarget = targetPos - SnakeLocation;

	float DeltaX = DirectionToTarget.X;
	float DeltaY = DirectionToTarget.Y;
	float DeltaZ = DirectionToTarget.Z;
	
	//UE_LOG(LogTemp, Warning, TEXT("x %f, y %f, z %f"), DeltaX,DeltaY,DeltaZ);

	if (!verticalTurn)
	{
		if (DeltaX > DeltaY)
		{
			if (DeltaX > 0)
			{
				if (ControlledSnake->worldDir == 'x' || ControlledSnake->worldDir == 'y')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->worldDir == 'Y')
				{
					ControlledSnake->Rotate('l');
				}
			}
			else
			{
				if (ControlledSnake->worldDir == 'X' || ControlledSnake->worldDir == 'Y')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->worldDir == 'y')
				{
					ControlledSnake->Rotate('l');
				}
			}
		}
		else
		{
			if (DeltaY > 0)
			{
				if (ControlledSnake->worldDir == 'y' || ControlledSnake->worldDir == 'X')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->worldDir == 'x')
				{
					ControlledSnake->Rotate('l');
				}
			}
			else
			{
				if (ControlledSnake->worldDir == 'Y' || ControlledSnake->worldDir == 'x')
				{
					ControlledSnake->Rotate('r');
				}
				else if (ControlledSnake->worldDir == 'X')
				{
					ControlledSnake->Rotate('l');
				}
			}
		}
	}
	else
	{
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
