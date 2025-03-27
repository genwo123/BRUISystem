// BRButton.h
#pragma once
#include "CoreMinimal.h"
#include "Components/Button.h"
#include "BRStyleData.h"
#include "BRButton.generated.h"

// UUserWidget�� �ƴ� UButton���� ���
UCLASS(Blueprintable, meta = (DisplayName = "BR Button"))
class BRUISYSTEM_API UBRButton : public UButton
{
    GENERATED_BODY()
public:
    UBRButton();

    // UButton�� �޼��� �������̵�
    virtual void SynchronizeProperties() override;

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonStyle(const FBRButtonStyle& InStyle);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetDisabled(bool bInIsDisabled);

    UFUNCTION(BlueprintPure, Category = "UI|Button")
    bool IsDisabled() const { return bIsDisabled; }

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonText(const FText& InText);

    UFUNCTION(BlueprintPure, Category = "UI|Button")
    FText GetButtonText() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FBRButtonStyle ButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FText ButtonText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bPlaySounds;

    // �̺�Ʈ ��������Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonClicked();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonHovered();

    UFUNCTION(BlueprintImplementableEvent, Category = "UI|Button")
    void BP_OnButtonUnhovered();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Button")
    bool bIsDisabled;

    // UButton �̺�Ʈ �ڵ鷯
    UFUNCTION()
    void OnButtonClicked();

    UFUNCTION()
    void OnButtonHovered();

    UFUNCTION()
    void OnButtonUnhovered();

    void UpdateButtonStyle();
    void PlaySound(class USoundBase* Sound);
};