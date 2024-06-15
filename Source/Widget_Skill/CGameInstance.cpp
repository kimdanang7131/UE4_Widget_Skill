#include "CGameInstance.h"
/////////////////
#include "Components/WidgetComponent.h"
#include "Widgets/CUserWidget_MainWindow.h"


// static은 .cpp에서 초기화 해야함
UCUserWidget_MainWindow* UCGameInstance::MainWindow = nullptr;

UCGameInstance::UCGameInstance()
{
	// #1. 콘텐츠 브라우저에서 가져와 등록
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

/** 프로그램 종료 시 호출 */
void UCGameInstance::Shutdown()
{
	if (MainWindow)
	{
		MainWindow->RemoveFromParent();
		MainWindow = nullptr;
	}
	Super::Shutdown();
}

/** GameInstance가 가장 먼저 생성되므로 다른곳에서 적절한 시기 때 실행 */
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


