// Copyright Your Company, All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetActivationChanged);

/**
 * BRWidget - 활성화 및 비활성화가 가능한 위젯의 기본 클래스
 * CommonActivatableWidget과 유사한 기능을 제공합니다.
 */
UCLASS(Blueprintable)
class BRUISYSTEM_API UBRWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRWidget(const FObjectInitializer& ObjectInitializer);

    // 활성화 상태 확인
    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    bool IsActivated() const { return bIsActive; }

    // 기존 BRUIStackManager와 호환되는 함수
    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = "UI|Lifecycle")
    virtual void Deactivate();

    // UUserWidget 오버라이드
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // 설정 프로퍼티
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bAutoActivate = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bIsBackHandler = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bIsModal = false;

    // 가시성 설정
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bSetVisibilityOnActivated = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation", meta = (EditCondition = "bSetVisibilityOnActivated"))
    ESlateVisibility ActivatedVisibility = ESlateVisibility::SelfHitTestInvisible;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation")
    bool bSetVisibilityOnDeactivated = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Activation", meta = (EditCondition = "bSetVisibilityOnDeactivated"))
    ESlateVisibility DeactivatedVisibility = ESlateVisibility::Collapsed;

    // 이벤트 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnWidgetActivationChanged OnWidgetActivated;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnWidgetActivationChanged OnWidgetDeactivated;

protected:
    // 활성화/비활성화 이벤트
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events", meta = (DisplayName = "On Activated"))
    void BP_OnActivated();
    virtual void NativeOnActivated();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Events", meta = (DisplayName = "On Deactivated"))
    void BP_OnDeactivated();
    virtual void NativeOnDeactivated();

    // 백 액션 처리
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|BackAction")
    bool BP_OnHandleBackAction();
    virtual bool NativeOnHandleBackAction();

    UFUNCTION()
    void HandleBackAction();

private:
    UPROPERTY(BlueprintReadOnly, Category = "Activation", meta = (AllowPrivateAccess = true))
    bool bIsActive = false;
};