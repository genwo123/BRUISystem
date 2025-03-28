// Copyright Your Company, All Rights Reserved.
#include "BRWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

UBRWidget::UBRWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bIsActive(false)
{
    // �⺻ ������
}

void UBRWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // �ڵ� Ȱ��ȭ �ɼ� 
    if (bAutoActivate)
    {
        UE_LOG(LogTemp, Log, TEXT("[%s] auto-activated"), *GetName());
        Activate();
    }
}

void UBRWidget::NativeDestruct()
{
    // ������ �ı��� �� ��Ȱ��ȭ
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
        // ���ü� ����
        if (bSetVisibilityOnActivated)
        {
            SetVisibility(ActivatedVisibility);
            UE_LOG(LogTemp, Log, TEXT("[%s] activated with visibility change"), *GetName());
        }

        // �������Ʈ �̺�Ʈ ȣ��
        BP_OnActivated();

        // ��������Ʈ ��ε�ĳ��Ʈ
        OnWidgetActivated.Broadcast();
    }
}

void UBRWidget::NativeOnDeactivated()
{
    // ���ü� ����
    if (bSetVisibilityOnDeactivated)
    {
        SetVisibility(DeactivatedVisibility);
        UE_LOG(LogTemp, Log, TEXT("[%s] deactivated with visibility change"), *GetName());
    }

    // �������Ʈ �̺�Ʈ ȣ��
    BP_OnDeactivated();

    // ��������Ʈ ��ε�ĳ��Ʈ
    OnWidgetDeactivated.Broadcast();
}

bool UBRWidget::NativeOnHandleBackAction()
{
    if (bIsBackHandler)
    {
        if (!BP_OnHandleBackAction())
        {
            // �⺻ ����: ��Ȱ��ȭ
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