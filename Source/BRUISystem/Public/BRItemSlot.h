// BRItemSlot.h
#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "BRItemSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSlotSelected, int32, SlotIndex);

UCLASS(Blueprintable, meta = (DisplayName = "BR Item Slot"))
class BRUISYSTEM_API UBRItemSlot : public UBorder
{
    GENERATED_BODY()

public:
    // 기본 생성자 추가
    UBRItemSlot();

    // Border 클래스의 메서드를 오버라이드하지 않음

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetItemIcon(UTexture2D* InTexture);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetItemCount(int32 InCount);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetSlotIndex(int32 InIndex);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    int32 GetSlotIndex() const { return SlotIndex; }

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void SetSelected(bool bInSelected);

    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    bool IsSelected() const { return bIsSelected; }

    UPROPERTY(BlueprintAssignable, Category = "UI|ItemSlot")
    FOnItemSlotSelected OnSlotSelected;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    bool bIsSelected;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    UTexture2D* ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 ItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    FLinearColor NormalColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    FLinearColor HoveredColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    FLinearColor SelectedColor;

    UPROPERTY(BlueprintReadOnly, Category = "UI|ItemSlot", meta = (BindWidget))
    class UImage* IconImage;

    UPROPERTY(BlueprintReadOnly, Category = "UI|ItemSlot", meta = (BindWidget))
    class UTextBlock* CountText;

    void UpdateSlotAppearance();
};