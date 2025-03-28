// Copyright Your Company, All Rights Reserved.
#include "BRWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

UBRWidget::UBRWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bIsActive(false)
{
    // 기본 생성자
}

void UBRWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 자동 활성화 옵션 
    if (bAutoActivate)
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] auto-activated"), *GetName());
        Activate();
    }
}

void UBRWidget::NativeDestruct()
{
    // 위젯이 파괴될 때 비활성화
    if (bIsActive)
    {
        Deactivate();
    }

    Super::NativeDestruct();
}

void UBRWidget::Activate()
{
    if (bIsActive)
        return;

    bIsActive = true;
    NativeOnActivated();
}

void UBRWidget::Deactivate()
{
    if (!bIsActive)
        return;

    bIsActive = false;
    NativeOnDeactivated();
}

void UBRWidget::NativeOnActivated()
{
    if (bIsActive)
    {
        // 가시성 설정
        if (bSetVisibilityOnActivated)
        {
            SetVisibility(ActivatedVisibility);
            UE_LOG(LogTemp, Log, TEXT("[%s] activated with visibility change"), *GetName());
        }

        // 블루프린트 이벤트 호출
        BP_OnActivated();

        // 델리게이트 브로드캐스트
        OnWidgetActivated.Broadcast();
    }
}

void UBRWidget::NativeOnDeactivated()
{
    // 가시성 설정
    if (bSetVisibilityOnDeactivated)
    {
        SetVisibility(DeactivatedVisibility);
        UE_LOG(LogTemp, Log, TEXT("[%s] deactivated with visibility change"), *GetName());
    }

    // 블루프린트 이벤트 호출
    BP_OnDeactivated();

    // 델리게이트 브로드캐스트
    OnWidgetDeactivated.Broadcast();
}

bool UBRWidget::NativeOnHandleBackAction()
{
    if (bIsBackHandler)
    {
        if (!BP_OnHandleBackAction())
        {
            // 기본 동작: 비활성화
            UE_LOG(LogTemp, Log, TEXT("[%s] handled back with default implementation. Deactivating immediately."), *GetName());
            Deactivate();
        }
        return true;
    }
    return false;
}

void UBRWidget::HandleBackAction()
{
    NativeOnHandleBackAction();
}