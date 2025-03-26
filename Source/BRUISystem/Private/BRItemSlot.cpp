// Copyright Your Company, All Rights Reserved.
#include "BRItemSlot.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Materials/MaterialInstanceDynamic.h"

UBRItemSlot::UBRItemSlot()
    : SlotIndex(0)
    , bIsSelected(false)
    , ItemIcon(nullptr)
    , ItemCount(0)
    , NormalColor(FLinearColor(0.2f, 0.2f, 0.2f, 1.0f))
    , HoveredColor(FLinearColor(0.3f, 0.3f, 0.3f, 1.0f))
    , SelectedColor(FLinearColor(0.4f, 0.4f, 0.8f, 1.0f))
{
    // 기본 테두리 스타일 설정
    SetBrushColor(NormalColor);
}

void UBRItemSlot::NativePreConstruct()
{
    Super::NativePreConstruct();

    // 위젯 생성 및 초기화
    if (!IconImage)
    {
        IconImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("IconImage"));
        if (IconImage)
        {
            AddChild(IconImage);
        }
    }

    if (!CountText)
    {
        CountText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CountText"));
        if (CountText)
        {
            AddChild(CountText);
            CountText->SetVisibility(ItemCount > 0 ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
        }
    }

    UpdateSlotAppearance();
}

void UBRItemSlot::NativeConstruct()
{
    Super::NativeConstruct();
}

void UBRItemSlot::NativeDestruct()
{
    Super::NativeDestruct();
}

FReply UBRItemSlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
    {
        SetSelected(true);
        if (OnSlotSelected.IsBound())
        {
            OnSlotSelected.Broadcast(SlotIndex);
        }
        return FReply::Handled();
    }

    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UBRItemSlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

    if (!bIsSelected)
    {
        SetBrushColor(HoveredColor);
    }
}

void UBRItemSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);

    if (!bIsSelected)
    {
        SetBrushColor(NormalColor);
    }
}

void UBRItemSlot::SetItemIcon(UTexture2D* InTexture)
{
    ItemIcon = InTexture;

    if (IconImage)
    {
        if (ItemIcon)
        {
            IconImage->SetBrushFromTexture(ItemIcon);
            IconImage->SetVisibility(ESlateVisibility::Visible);
        }
        else
        {
            IconImage->SetVisibility(ESlateVisibility::Hidden);
        }
    }
}

void UBRItemSlot::SetItemCount(int32 InCount)
{
    ItemCount = InCount;

    if (CountText)
    {
        if (ItemCount > 1)