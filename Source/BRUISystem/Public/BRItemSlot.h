// Copyright Your Company, All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRItemSlot.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSlotSelected, int32, SlotIndex);

/**
 * BRItemSlot - �κ��丮 ������ ���� ����
 * �������Ʈ���� ���� Ȯ���� �� �ֵ��� ����Ǿ����ϴ�
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

    // ���� �̺�Ʈ ��������Ʈ
    UPROPERTY(BlueprintAssignable, Category = "UI|ItemSlot|Event")
    FOnItemSlotSelected OnSlotSelected;

    // ���� �Ӽ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 SlotIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    UTexture2D* ItemIcon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    int32 ItemCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot")
    bool bIsSelected;

    // ��Ÿ�� �Ӽ�
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor NormalColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor HoveredColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI|ItemSlot|Style")
    FLinearColor SelectedColor;

    // ���� �޼���
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
    // �������Ʈ���� ������ ���� ������Ʈ
    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UBorder* BorderWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UButton* ButtonWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UImage* IconWidget;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category = "UI|ItemSlot")
    class UTextBlock* CountWidget;

    // �̺�Ʈ �ڵ鷯
    UFUNCTION()
    void HandleButtonClicked();

    UFUNCTION()
    void HandleButtonHovered();

    UFUNCTION()
    void HandleButtonUnhovered();

    // �������Ʈ���� �������̵��� �̺�Ʈ
    UFUNCTION(BlueprintImplementableEvent, Category = "UI|ItemSlot")
    void BP_OnSlotSelected(int32 InSlotIndex);

    // ���� �ܰ� ������Ʈ
    UFUNCTION(BlueprintCallable, Category = "UI|ItemSlot")
    void UpdateSlotAppearance();
};