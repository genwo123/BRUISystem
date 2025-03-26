// Copyright Your Company, All Rights Reserved.
#include "BRWidget.h" 
#include "Kismet/GameplayStatics.h"

UBRWidget::UBRWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UBRWidget::NativeConstruct()
{
    Super::NativeConstruct();
}

void UBRWidget::Activate()
{
    if (!bIsActive)
    {
        bIsActive = true;
        SetVisibility(ESlateVisibility::Visible);
        OnActivated();
    }
}

void UBRWidget::Deactivate()
{
    if (bIsActive)
    {
        bIsActive = false;
        SetVisibility(ESlateVisibility::Collapsed);
        OnDeactivated();
    }
}

//void UBRWidget::PlaySound(USoundBase* Sound)
//{
//    if (Sound && IsValid(this) && GetWorld())
//    {
//        UGameplayStatics::PlaySound2D(GetWorld(), Sound);
//    }
//}