#include "ScoresDisplay.h"
#include "Components/TextBlock.h"

void UScoresDisplay::SetTimeLeft(int32 Seconds)
{
	const int32 M = Seconds / 60;
	const int32 S = Seconds % 60;
	if (TimeText)
	{
		TimeText->SetText(FText::FromString(FString::Printf(TEXT("%02d:%02d"), M, S)));
	}
}