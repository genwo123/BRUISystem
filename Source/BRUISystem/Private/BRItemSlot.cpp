// Copyright Your Company, All Rights Reserved.
#include "BRItemSlot.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

UBRItemSlot::UBRItemSlot(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SlotIndex(-1)
    , ItemIcon(nullptr)
    , ItemCount(0)
    , bIsSelected(false)
{
    // 기본 색상 초기화
    NormalColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);
    HoveredColor = FLinearColor(0.7f, 0.7f, 0.7f, 1.0f);
    SelectedColor = FLinearColor(0.9f, 0.9f, 0.3f, 1.0f);
}

void UBRItemSlot::NativePreConstruct()
{
    Super::NativePreConstruct();

    // 디자이너에서 편집된 값으로 UI 업데이트
    UpdateSlotAppearance();
}

void UBRItemSlot::NativeConstruct()
{
    Super::NativeConstruct();

    // 버튼 이벤트 바인딩
    if (ButtonWidget)
    {
        ButtonWidget->OnClicked.AddDynamic(this, &UBRItemSlot::HandleButtonClicked);
        ButtonWidget->OnHovered.AddDynamic(this, &UBRItemSlot::HandleButtonHovered);
        ButtonWidget->OnUnhovered.AddDynamic(this, &UBRItemSlot::HandleButtonUnhovered);
    }

    // 아이콘 설정
    if (IconWidget)
    {
        IconWidget->SetBrushFromTexture(ItemIcon);
        IconWidget->SetVisibility(ItemIcon ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    // 카운트 설정
    if (CountWidget)
    {
        CountWidget->SetText(FText::AsNumber(ItemCount));
        CountWidget->SetVisibility(ItemCount > 1 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    // 외관 업데이트
    UpdateSlotAppearance();
}

void UBRItemSlot::NativeDestruct()
{
    // 버튼 이벤트 바인딩 해제
    if (ButtonWidget)
    {
        ButtonWidget->OnClicked.RemoveAll(this);
        ButtonWidget->OnHovered.RemoveAll(this);
        ButtonWidget->OnUnhovered.RemoveAll(this);
    }

    Super::NativeDestruct();
}

void UBRItemSlot::SetItemIcon(UTexture2D* InTexture)
{
    ItemIcon = InTexture;

    if (IconWidget)
    {
        IconWidget->SetBrushFromTexture(ItemIcon);
        IconWidget->SetVisibility(ItemIcon ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
}

void UBRItemSlot::SetItemCount(int32 InCount)
{
    ItemCount = InCount;

    if (CountWidget)
    {
        CountWidget->SetText(FText::AsNumber(ItemCount));
        CountWidget->SetVisibility(ItemCount > 1 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
}

void UBRItemSlot::SetSlotIndex(int32 InIndex)
{
    SlotIndex = InIndex;
}

void UBRItemSlot::SetSelected(bool bInSelected)
{
    bIsSelected = bInSelected;
    UpdateSlotAppearance();

    if (bIsSelected)
    {
        BP_OnSlotSelected(SlotIndex);
        OnSlotSelected.Broadcast(SlotIndex);
    }
}

void UBRItemSlot::HandleButtonClicked()
{
    SetSelected(true);
}

void UBRItemSlot::HandleButtonHovered()
{
    if (!bIsSelected && BorderWidget)
    {
        BorderWidget->SetBrushColor(HoveredColor);
    }
}

void UBRItemSlot::HandleButtonUnhovered()
{
    if (!bIsSelected && BorderWidget)
    {
        BorderWidget->SetBrushColor(NormalColor);
    }
}

void UBRItemSlot::UpdateSlotAppearance()
{
    // 보더 스타일 업데이트
    if (BorderWidget)
    {
        BorderWidget->SetBrushColor(bIsSelected ? SelectedColor : NormalColor);
    }

    // 아이콘 가시성 업데이트
    if (IconWidget)
    {
        IconWidget->SetVisibility(ItemIcon ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    // 아이템 카운트 가시성 업데이트
    if (CountWidget)
    {
        CountWidget->SetVisibility(ItemCount > 1 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
}