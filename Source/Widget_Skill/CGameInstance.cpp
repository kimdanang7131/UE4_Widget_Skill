#include "CGameInstance.h"
/////////////////
#include "Components/WidgetComponent.h"
#include "Widgets/CUserWidget_MainWindow.h"


// static�� .cpp���� �ʱ�ȭ �ؾ���
UCUserWidget_MainWindow* UCGameInstance::MainWindow = nullptr;

UCGameInstance::UCGameInstance()
{
	// #1. ������ ���������� ������ ���
	ConstructorHelpers::FClassFinder<UUserWidget> MainWindowBPClass(TEXT("WidgetBlueprint'/Game/Blueprints/Widgets/WBP_MainWindow.WBP_MainWindow_C'"));
	if (MainWindowBPClass.Class != nullptr)
	{
		MainWindowClass = MainWindowBPClass.Class;
	}
}

void UCGameInstance::Init()
{
	Super::Init();
}

/** ���α׷� ���� �� ȣ�� */
void UCGameInstance::Shutdown()
{
	if (MainWindow)
	{
		MainWindow->RemoveFromParent();
		MainWindow = nullptr;
	}
	Super::Shutdown();
}

/** GameInstance�� ���� ���� �����ǹǷ� �ٸ������� ������ �ñ� �� ���� */
void UCGameInstance::MainWindowAddToViewport()
{
	if (MainWindowClass)
	{
		MainWindow = CreateWidget<UCUserWidget_MainWindow>(this, MainWindowClass);
	}

	if (MainWindow)
	{
		MainWindow->AddToViewport();
	}
}


