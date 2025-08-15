#include "ScoresDisplay.h"
#include "Components/TextBlock.h"

void UScoresDisplay::NativeConstruct()
{
	Super::NativeConstruct();

	if (MainText)
	{
		MainText->SetText(FText::FromString("Initialized"));
	}
}

void UScoresDisplay::SetText(const FString& NewText)
{
	if (MainText)
	{
		MainText->SetText(FText::FromString(NewText));
	}
}