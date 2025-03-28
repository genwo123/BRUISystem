// Copyright Your Company, All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetActivationChanged);

/**
 * BRWidget - Ȱ��ȭ �� ��Ȱ��ȭ�� ������ ������ �⺻ Ŭ����
 * CommonActivatableWidget�� ������ ����� �����մϴ�.
 */
UCLASS(Blueprintable)
class BRUISYSTEM_API UBRWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRWidget(const FObjectInitializer& ObjectInitializer);

    // Ȱ��ȭ ���� Ȯ��
    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    bool IsActivated() const { return bIsActive; }

    // ���� BRUIStackManager�� ȣȯ�Ǵ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Deactivate();

    // UUserWidget �������̵�
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // ���� ������Ƽ
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bAutoActivate = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bIsBackHandler = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bIsModal = false;

    // ���ü� ����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bSetVisibilityOnActivated = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation", meta = (EditCondition = "bSetVisibilityOnActivated"))
    ESlateVisibility ActivatedVisibility = ESlateVisibility::SelfHitTestInvisible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bSetVisibilityOnDeactivated = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation", meta = (EditCondition = "bSetVisibilityOnDeactivated"))
    ESlateVisibility DeactivatedVisibility = ESlateVisibility::Collapsed;

    // �̺�Ʈ ��������Ʈ
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnWidgetActivationChanged OnWidgetActivated;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnWidgetActivationChanged OnWidgetDeactivated;

protected:
    // Ȱ��ȭ/��Ȱ��ȭ �̺�Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events", meta = (DisplayName = "On Activated"))
    void BP_OnActivated();
    virtual void NativeOnActivated();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events", meta = (DisplayName = "On Deactivated"))
    void BP_OnDeactivated();
    virtual void NativeOnDeactivated();

    // �� �׼� ó��
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|BackAction")
    bool BP_OnHandleBackAction();
    virtual bool NativeOnHandleBackAction();

    UFUNCTION()
    void HandleBackAction();

private:
    UPROPERTY(BlueprintReadOnly, Category = "Activation", meta = (AllowPrivateAccess = true))
    bool bIsActive = false;
};