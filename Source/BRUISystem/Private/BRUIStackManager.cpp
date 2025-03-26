// Copyright Your Company, All Rights Reserved.
#include "BRUIStackManager.h"
#include "BRWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UBRUIStackManager::UBRUIStackManager()
{
}

UBRWidget* UBRUIStackManager::PushWidget(TSubclassOf<UBRWidget> WidgetClass)
{
    if (!WidgetClass)
    {
        return nullptr;
    }

    UWorld* World = GetWorld();
    if (!World)
    {
        return nullptr;
    }

    APlayerController* PC = World->GetFirstPlayerController();
    if (!PC)
    {
        return nullptr;
    }

    UBRWidget* NewWidget = CreateWidget<UBRWidget>(PC, WidgetClass);
    if (!NewWidget)
    {
        return nullptr;
    }

    if (PushExistingWidget(NewWidget))
    {
        return NewWidget;
    }

    NewWidget->RemoveFromParent();
    return nullptr;
}

void UBRUIStackManager::PopWidget()
{
    UBRWidget* Widget = PopAndGetWidget();
    if (Widget)
    {
        Widget->RemoveFromParent();
    }
}

void UBRUIStackManager::PopAllWidgets()
{
    ClearStack();
}

UBRWidget* UBRUIStackManager::ReplaceWidget(TSubclassOf<UBRWidget> WidgetClass)
{
    PopWidget();
    return PushWidget(WidgetClass);
}

UBRWidget* UBRUIStackManager::GetActiveWidget() const
{
    return GetTopWidget();
}

TArray<UBRWidget*> UBRUIStackManager::GetWidgetStack() const
{
    return WidgetStack;
}

bool UBRUIStackManager::PushExistingWidget(UBRWidget* Widget)
{
    if (!IsValid(Widget))
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUIStackManager: Attempted to push invalid widget to the stack"));
        return false;
    }

    UBRWidget* TopWidget = GetTopWidget();
    if (TopWidget)
    {
        TopWidget->Deactivate();
    }

    WidgetStack.Add(Widget);
    Widget->Activate();

    return true;
}

UBRWidget* UBRUIStackManager::PopAndGetWidget()
{
    if (WidgetStack.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("BRUIStackManager: Attempted to pop from empty stack"));
        return nullptr;
    }

    UBRWidget* TopWidget = WidgetStack.Pop();
    TopWidget->Deactivate();

    UBRWidget* NewTopWidget = GetTopWidget();
    if (NewTopWidget)
    {
        NewTopWidget->Activate();
    }

    return TopWidget;
}

bool UBRUIStackManager::RemoveWidget(UBRWidget* Widget)
{
    if (!IsValid(Widget) || WidgetStack.Num() == 0)
    {
        return false;
    }

    int32 Index = WidgetStack.Find(Widget);
    if (Index == INDEX_NONE)
    {
        return false;
    }

    bool bWasTopWidget = (Index == WidgetStack.Num() - 1);

    WidgetStack.RemoveAt(Index);
    Widget->Deactivate();

    if (bWasTopWidget)
    {
        UBRWidget* NewTopWidget = GetTopWidget();
        if (NewTopWidget)
        {
            NewTopWidget->Activate();
        }
    }

    return true;
}

void UBRUIStackManager::ClearStack()
{
    for (UBRWidget* Widget : WidgetStack)
    {
        if (IsValid(Widget))
        {
            Widget->Deactivate();
            Widget->RemoveFromParent();
        }
    }

    WidgetStack.Empty();
}

UBRWidget* UBRUIStackManager::GetTopWidget() const
{
    if (WidgetStack.Num() == 0)
    {
        return nullptr;
    }

    return WidgetStack.Last();
}

bool UBRUIStackManager::HasWidgets() const
{
    return WidgetStack.Num() > 0;
}

bool UBRUIStackManager::ContainsWidgetOfClass(TSubclassOf<UBRWidget> WidgetClass) const
{
    if (!WidgetClass)
    {
        return false;
    }

    for (UBRWidget* Widget : WidgetStack)
    {
        if (IsValid(Widget) && Widget->IsA(WidgetClass))
        {
            return true;
        }
    }

    return false;
}