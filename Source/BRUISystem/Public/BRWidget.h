#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRWidget.generated.h"

/**
 * 기본 위젯 클래스 - 모든 UI 요소의 부모
 */
UCLASS(Abstract, Blueprintable)
class BRUISYSTEM_API UBRWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRWidget(const FObjectInitializer& ObjectInitializer);

    // 위젯 활성화/비활성화 메서드
    UFUNCTION(BlueprintCallable, Category = "BR_UI")
    virtual void Activate();

    UFUNCTION(BlueprintCallable, Category = "BR_UI")
    virtual void Deactivate();

    //// 사운드 재생 기능
    //UFUNCTION(BlueprintCallable, Category = "BR|UI|Sound")
    //void PlaySound(class USoundBase* Sound);

    // 위젯 상태 확인
    UFUNCTION(BlueprintPure, Category = "BR_UI")
    bool IsActive() const { return bIsActive; }

protected:
    // 위젯 상태
    UPROPERTY(BlueprintReadOnly, Category = "BR_UI")
    bool bIsActive = false;

    // 위젯이 활성화 될 때의 이벤트
    UFUNCTION(BlueprintImplementableEvent, Category = "BR_UI")
    void OnActivated();

    // 위젯이 비활성화 될 때의 이벤트
    UFUNCTION(BlueprintImplementableEvent, Category = "BR_UI")
    void OnDeactivated();

    virtual void NativeConstruct() override;
};