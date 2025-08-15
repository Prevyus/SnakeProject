#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoresDisplay.generated.h"

class UTextBlock;

UCLASS()
class SNAKEGAME_API UScoresDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetTimeLeft(int32 Seconds);

protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* TimeText;

};
