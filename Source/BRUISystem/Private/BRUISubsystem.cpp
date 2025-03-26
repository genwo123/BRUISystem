// Copyright Your Company, All Rights Reserved.
#include "BRUISubsystem.h"
#include "BRWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void UBRUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    MainStackManager = NewObject<UBRUIStackManager>(this);
    PopupStackManager = NewObject<UBRUIStackManager>(this);

    UE_LOG(LogTemp, Log, TEXT("BRUISubsystem: Initialized"));
}

void UBRUISubsystem::Deinitialize()
{
    if (MainStackManager)
    {
        MainStackManager->ClearStack();
        MainStackManager = nullptr;
    }

    if (PopupStackManager)
    {
        PopupStackManager->ClearStack();
        PopupStackManager = nullptr;
    }

    UE_LOG(LogTemp, Log, TEXT("BRUISubsystem: Deinitialized"));
}

UBRWidget* UBRUISubsystem::CreateWidget(TSubclassOf<UBRWidget> WidgetClass)
{
    if (!WidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: Invalid widget class provided"));
        return nullptr;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: Failed to get World"));
        return nullptr;
    }

    APlayerController* PC = World->GetFirstPlayerController();
    if (!PC)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: Failed to get PlayerController"));
        return nullptr;
    }

    UBRWidget* NewWidget = CreateWidget<UBRWidget>(PC, WidgetClass);
    if (!NewWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: Failed to create widget"));
        return nullptr;
    }

    return NewWidget;
}

bool UBRUISubsystem::PushMainWidget(UBRWidget* Widget)
{
    if (!MainStackManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: MainStackManager is invalid"));
        return false;
    }

    return MainStackManager->PushExistingWidget(Widget);
}

UBRWidget* UBRUISubsystem::PopMainWidget()
{
    if (!MainStackManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: MainStackManager is invalid"));
        return nullptr;
    }

    return MainStackManager->PopAndGetWidget();
}

bool UBRUISubsystem::PushPopupWidget(UBRWidget* Widget)
{
    if (!PopupStackManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: PopupStackManager is invalid"));
        return false;
    }

    return PopupStackManager->PushExistingWidget(Widget);
}

UBRWidget* UBRUISubsystem::PopPopupWidget()
{
    if (!PopupStackManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUISubsystem: PopupStackManager is invalid"));
        return nullptr;
    }

    return PopupStackManager->PopAndGetWidget();
}

UBRWidget* UBRUISubsystem::CreateAndPushMainWidget(TSubclassOf<UBRWidget> WidgetClass)
{
    UBRWidget* NewWidget = CreateWidget(WidgetClass);
    if (!NewWidget)
    {
        return nullptr;
    }

    if (!PushMainWidget(NewWidget))
    {
        NewWidget->RemoveFromParent();
        return nullptr;
    }

    return NewWidget;
}

UBRWidget* UBRUISubsystem::CreateAndPushPopupWidget(TSubclassOf<UBRWidget> WidgetClass)
{
    UBRWidget* NewWidget = CreateWidget(WidgetClass);
    if (!NewWidget)
    {
        return nullptr;
    }

    if (!PushPopupWidget(NewWidget))
    {
        NewWidget->RemoveFromParent();
        return nullptr;
    }

    return NewWidget;
}