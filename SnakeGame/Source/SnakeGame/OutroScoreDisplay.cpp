#include "OutroScoreDisplay.h"
#include "Components/TextBlock.h"

void UOutroScoreDisplay::NativeConstruct()
{
	Super::NativeConstruct();

	if (MainText)
	{
		MainText->SetText(FText::FromString("Initialized"));
	}
}

void UOutroScoreDisplay::SetText(const FString& NewText)
{
	if (MainText)
	{
		MainText->SetText(FText::FromString(NewText));
	}
}
