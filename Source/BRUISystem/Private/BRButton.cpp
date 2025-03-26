// Copyright Your Company, All Rights Reserved.
#include "BRButton.h"
#include "Components/TextBlock.h"
#include "Components/ButtonSlot.h"
#include "Kismet/GameplayStatics.h"

UBRButton::UBRButton()
    : bIsDisabled(false)
    , bPlaySounds(true)
{
    ButtonStyle = FBRButtonStyle();
}

void UBRButton::NativePreConstruct()
{
    Super::NativePreConstruct();

    UpdateButtonStyle();

    if (!TextBlock)
    {
        TextBlock = NewObject<UTextBlock>(this);
        if (TextBlock)
        {
            UButtonSlot* ButtonSlot = Cast<UButtonSlot>(AddChild(TextBlock));
            if (ButtonSlot)
            {
                ButtonSlot->SetHorizontalAlignment(HAlign_Center);
                ButtonSlot->SetVerticalAlignment(VAlign_Center);
            }
        }
    }

    if (TextBlock)
    {
        TextBlock->SetText(ButtonText);
        TextBlock->SetColorAndOpacity(ButtonStyle.TextColor);
    }
}

void UBRButton::NativeConstruct()
{
    Super::NativeConstruct();
}

void UBRButton::NativeDestruct()
{
    Super::NativeDestruct();
}

void UBRButton::SetButtonStyle(const FBRButtonStyle& InStyle)
{
    ButtonStyle = InStyle;
    UpdateButtonStyle();
}

void UBRButton::SetDisabled(bool bInIsDisabled)
{
    if (bIsDisabled != bInIsDisabled)
    {
        bIsDisabled = bInIsDisabled;
        UpdateButtonStyle();
    }
}

void UBRButton::SetButtonText(const FText& InText)
{
    ButtonText = InText;

    if (TextBlock)
    {
        TextBlock->SetText(ButtonText);
    }
}

FText UBRButton::GetButtonText() const
{
    return ButtonText;
}

FReply UBRButton::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (!bIsDisabled)
    {
        SetColorAndOpacity(ButtonStyle.HoveredColor);

        if (bPlaySounds && ButtonStyle.HoveredSound)
        {
            PlaySound(ButtonStyle.HoveredSound);
        }
    }

    return Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
}

FReply UBRButton::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    if (!bIsDisabled)
    {
        SetColorAndOpacity(ButtonStyle.NormalColor);
    }

    return Super::NativeOnMouseLeave(InMouseEvent);
}

FReply UBRButton::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (!bIsDisabled && InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
    {
        SetColorAndOpacity(ButtonStyle.PressedColor);

        if (bPlaySounds && ButtonStyle.PressedSound)
        {
            PlaySound(ButtonStyle.PressedSound);
        }
    }

    return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UBRButton::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (!bIsDisabled && InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        if (IsHovered())
        {
            SetColorAndOpacity(ButtonStyle.HoveredColor);
        }
        else
        {
            SetColorAndOpacity(ButtonStyle.NormalColor);
        }
    }

    return Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);
}

void UBRButton::UpdateButtonStyle()
{
    if (bIsDisabled)
    {
        SetColorAndOpacity(ButtonStyle.DisabledColor);
        if (TextBlock)
        {
            TextBlock->SetColorAndOpacity(ButtonStyle.DisabledTextColor);
        }
    }
    else
    {
        SetColorAndOpacity(ButtonStyle.NormalColor);
        if (TextBlock)
        {
            TextBlock->SetColorAndOpacity(ButtonStyle.TextColor);
        }
    }

    if (!bIsDisabled)
    {
        SetStyle(ButtonStyle.Style);
    }
    else
    {
        SetStyle(ButtonStyle.DisabledStyle);
    }
}

void UBRButton::PlaySound(USoundBase* Sound)
{
    if (Sound && IsValid(this) && GetWorld())
    {
        UGameplayStatics::PlaySound2D(GetWorld(), Sound);
    }
}