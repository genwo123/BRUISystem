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
 * BRButton - Ŀ���� ��ư ����
 * �������Ʈ���� ���� Ȯ�� �����մϴ�
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

    // ��ư �̺�Ʈ ��������Ʈ
    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonClicked OnButtonClicked;

    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonHovered OnButtonHovered;

    UPROPERTY(BlueprintAssignable, Category = "UI|Button|Event")
    FOnBRButtonUnhovered OnButtonUnhovered;

    // ��ư �Ӽ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FText ButtonText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FBRButtonStyle ButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bIsDisabled;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bPlaySounds;

    // ��ư ���� �޼���
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
    // �������Ʈ���� ������ ���� ������Ʈ
    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|Button")
    class UButton* ButtonWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|Button")
    class UTextBlock* TextWidget;

    // ���� �̺�Ʈ �ڵ鷯
    UFUNCTION()
    void HandleButtonClicked();

    UFUNCTION()
    void HandleButtonHovered();

    UFUNCTION()
    void HandleButtonUnhovered();

    // �������Ʈ���� �������̵��� �̺�Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonClicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonHovered();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonUnhovered();

    // ��ư ��Ÿ�� ������Ʈ
    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void UpdateButtonStyle();

    void PlaySound(class USoundBase* Sound);
};