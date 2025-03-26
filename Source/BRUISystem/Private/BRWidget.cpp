// Copyright Your Company, All Rights Reserved.
#include "BRWidget.h"
#include "Net/UnrealNetwork.h"

UBRWidget::UBRWidget(const FObjectInitializer& ObjectInitializer)
    : UUserWidget(ObjectInitializer)
{
    bIsActive = false;
}

void UBRWidget::NativeConstruct()
{
    UUserWidget::NativeConstruct();

    // Default to collapsed visibility
    SetVisibility(ESlateVisibility::Collapsed);
}

void UBRWidget::NativeDestruct()
{
    // Ensure proper cleanup
    if (bIsActive)
    {
        Deactivate();
    }

    UUserWidget::NativeDestruct();
}

void UBRWidget::Activate()
{
    if (bIsActive)
    {
        return;
    }

    bIsActive = true;
    SetVisibility(ESlateVisibility::Visible);

    // Broadcast blueprint event
    OnWidgetActivated();
}

void UBRWidget::Deactivate()
{
    if (!bIsActive)
    {
        return;
    }

    bIsActive = false;
    SetVisibility(ESlateVisibility::Collapsed);

    // Broadcast blueprint event
    OnWidgetDeactivated();
}

void UBRWidget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Register replicated properties
    DOREPLIFETIME(UBRWidget, bIsActive);
}