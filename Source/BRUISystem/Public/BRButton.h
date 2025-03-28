// Copyright Your Company, All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRStyleData.h"
#include "BRButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBRButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBRButtonHovered);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBRButtonUnhovered);

/**
 * BRButton - 커스텀 버튼 위젯
 * 블루프린트에서 쉽게 확장 가능합니다
 */
UCLASS(Blueprintable, meta = (DisplayName = "BR Button"))
class BRUISYSTEM_API UBRButton : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRButton(const FObjectInitializer& ObjectInitializer);

    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // 버튼 이벤트 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonClicked OnButtonClicked;

    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonHovered OnButtonHovered;

    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonUnhovered OnButtonUnhovered;

    // 버튼 속성
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FText ButtonText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FBRButtonStyle ButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bIsDisabled;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bPlaySounds;

    // 버튼 동작 메서드
    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonText(const FText& InText);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonStyle(const FBRButtonStyle& InStyle);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetDisabled(bool bInIsDisabled);

    UFUNCTION(BlueprintPure, Category = "UI|Button")
    FText GetButtonText() const;

    UFUNCTION(BlueprintPure, Category = "UI|Button")
    bool IsDisabled() const { return bIsDisabled; }

protected:
    // 블루프린트에서 생성할 위젯 컴포넌트
    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|Button")
    class UButton* ButtonWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|Button")
    class UTextBlock* TextWidget;

    // 내부 이벤트 핸들러
    UFUNCTION()
    void HandleButtonClicked();

    UFUNCTION()
    void HandleButtonHovered();

    UFUNCTION()
    void HandleButtonUnhovered();

    // 블루프린트에서 오버라이드할 이벤트
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonClicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonHovered();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonUnhovered();

    // 버튼 스타일 업데이트
    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void UpdateButtonStyle();

    void PlaySound(class USoundBase* Sound);
};