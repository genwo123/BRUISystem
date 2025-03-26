// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "BRStyleData.h"
#include "BRButton.generated.h"

UCLASS()
class BRUISYSTEM_API UBRButton : public UButton
{
    GENERATED_BODY()

public:
    UBRButton();

    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonStyle(const FBRButtonStyle& InStyle);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetDisabled(bool bInIsDisabled);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    bool IsDisabled() const { return bIsDisabled; }

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    void SetButtonText(const FText& InText);

    UFUNCTION(BlueprintCallable, Category = "UI|Button")
    FText GetButtonText() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FBRButtonStyle ButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    FText ButtonText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|Button")
    bool bPlaySounds;

protected:
    virtual FReply NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI|Button")
    bool bIsDisabled;

    UPROPERTY(BlueprintReadOnly, Category = "UI|Button")
    class UTextBlock* TextBlock;

    void UpdateButtonStyle();
    void PlaySound(class USoundBase* Sound);
};