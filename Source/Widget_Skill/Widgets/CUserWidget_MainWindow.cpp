#include "CUserWidget_MainWindow.h"
////////////
#include "CUserWidget_SkillWindow.h"
#include "Kismet/GameplayStatics.h"

void UCUserWidget_MainWindow::SetSkillWindowVisibility(bool bIsvisible)
{
	if (SkillWindow)
	{
		//ESlateVisibility EVisibility;
		if (bIsvisible)
		{
			SkillWindow->SetVisibility(ESlateVisibility::Visible);
			UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(FInputModeGameAndUI());
			UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(bIsvisible);

			if (OnSkillWindowDelegate.IsBound())
			{
				OnSkillWindowDelegate.Broadcast();
			}
		}
		else
		{
			SkillWindow->SetVisibility(ESlateVisibility::Hidden);
			UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(bIsvisible);
			UGameplayStatics::GetPlayerController(this, 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}