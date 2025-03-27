// BRItemSlot.cpp
#include "BRItemSlot.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

UBRItemSlot::UBRItemSlot()
{
    SlotIndex = -1;
    bIsSelected = false;
    ItemIcon = nullptr;
    ItemCount = 0;

    NormalColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);
    HoveredColor = FLinearColor(0.7f, 0.7f, 0.7f, 1.0f);
    SelectedColor = FLinearColor(0.9f, 0.9f, 0.3f, 1.0f);
}

void UBRItemSlot::SetItemIcon(UTexture2D* InTexture)
{
    ItemIcon = InTexture;

    if (IconImage)
    {
        IconImage->SetBrushFromTexture(ItemIcon);
        IconImage->SetVisibility(ItemIcon ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    UpdateSlotAppearance();
}

void UBRItemSlot::SetItemCount(int32 InCount)
{
    ItemCount = InCount;

    if (CountText)
    {
        CountText->SetText(FText::AsNumber(ItemCount));
        CountText->SetVisibility(ItemCount > 1 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
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
        OnSlotSelected.Broadcast(SlotIndex);
    }
}

void UBRItemSlot::UpdateSlotAppearance()
{
    SetBrushColor(bIsSelected ? SelectedColor : NormalColor);

    if (IconImage)
    {
        IconImage->SetVisibility(ItemIcon ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }

    if (CountText)
    {
        CountText->SetVisibility(ItemCount > 1 ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
}