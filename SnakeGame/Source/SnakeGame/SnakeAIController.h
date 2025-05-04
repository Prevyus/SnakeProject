#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "SnakeAIController.generated.h"

UCLASS()
class SNAKEGAME_API ASnakeAIController : public AController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	class ASnakePlayer* ControlledSnake;

	void MakeDecision();

	FVector targetPos = FVector(3000, 1300, 700);
	
};
