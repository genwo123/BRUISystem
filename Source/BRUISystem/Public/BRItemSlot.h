// Copyright Your Company, All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRItemSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSlotSelected, int32, SlotIndex);

/**
 * BRItemSlot - 인벤토리 아이템 슬롯 위젯
 * 블루프린트에서 쉽게 확장할 수 있도록 설계되었습니다
 */
UCLASS(Blueprintable, meta = (DisplayName = "BR Item Slot"))
class BRUISYSTEM_API UBRItemSlot : public UUserWidget
{
    GENERATED_BODY()

public:
    UBRItemSlot(const FObjectInitializer& ObjectInitializer);

    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // 슬롯 이벤트 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "UI|ItemSlot|Event")
    FOnItemSlotSelected OnSlotSelected;

    // 슬롯 속성
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    UTexture2D* ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 ItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    bool bIsSelected;

    // 스타일 속성
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor NormalColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor HoveredColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor SelectedColor;

    // 슬롯 메서드
    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetItemIcon(UTexture2D* InTexture);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetItemCount(int32 InCount);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetSlotIndex(int32 InIndex);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetSelected(bool bInSelected);

    UFUNCTION(BlueprintPure, Category = "UI|ItemSlot")
    int32 GetSlotIndex() const { return SlotIndex; }

    UFUNCTION(BlueprintPure, Category = "UI|ItemSlot")
    bool IsSelected() const { return bIsSelected; }

protected:
    // 블루프린트에서 생성할 위젯 컴포넌트
    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UBorder* BorderWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UButton* ButtonWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UImage* IconWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UTextBlock* CountWidget;

    // 이벤트 핸들러
    UFUNCTION()
    void HandleButtonClicked();

    UFUNCTION()
    void HandleButtonHovered();

    UFUNCTION()
    void HandleButtonUnhovered();

    // 블루프린트에서 오버라이드할 이벤트
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|ItemSlot")
    void BP_OnSlotSelected(int32 InSlotIndex);

    // 슬롯 외관 업데이트
    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void UpdateSlotAppearance();
};