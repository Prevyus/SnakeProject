#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OutroScoreDisplay.generated.h"

class UTextBlock;

UCLASS()
class SNAKEGAME_API UOutroScoreDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetText(const FString& NewText);

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MainText;
};
