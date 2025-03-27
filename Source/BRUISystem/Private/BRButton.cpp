// BRButton.cpp
#include "BRButton.h"
#include "Kismet/GameplayStatics.h"

UBRButton::UBRButton()
{
    bPlaySounds = true;
    bIsDisabled = false;
    ButtonStyle = FBRButtonStyle();

    // 기본 이벤트 바인딩
    OnClicked.AddDynamic(this, &UBRButton::OnButtonClicked);
    OnHovered.AddDynamic(this, &UBRButton::OnButtonHovered);
    OnUnhovered.AddDynamic(this, &UBRButton::OnButtonUnhovered);
}

void UBRButton::SynchronizeProperties()
{
    Super::SynchronizeProperties();
    UpdateButtonStyle();
}

void UBRButton::OnButtonClicked()
{
    if (!bIsDisabled)
    {
        if (bPlaySounds && ButtonStyle.PressedSound)
        {
            PlaySound(ButtonStyle.PressedSound);
        }

        // 블루프린트 이벤트 호출
        BP_OnButtonClicked();
    }
}

void UBRButton::OnButtonHovered()
{
    if (!bIsDisabled)
    {
        if (bPlaySounds && ButtonStyle.HoveredSound)
        {
            PlaySound(ButtonStyle.HoveredSound);
        }

        BP_OnButtonHovered();
    }
}

void UBRButton::OnButtonUnhovered()
{
    if (!bIsDisabled)
    {
        BP_OnButtonUnhovered();
    }
}

void UBRButton::SetButtonStyle(const FBRButtonStyle& InStyle)
{
    ButtonStyle = InStyle;
    UpdateButtonStyle();
}

void UBRButton::SetDisabled(bool bInIsDisabled)
{
    bIsDisabled = bInIsDisabled;
    UpdateButtonStyle();
    SetIsEnabled(!bIsDisabled);
}

void UBRButton::SetButtonText(const FText& InText)
{
    ButtonText = InText;
    // TextBlock이 없으므로 여기서는 아무것도 하지 않음
    // UButton은 텍스트를 직접 포함하지 않음
}

FText UBRButton::GetButtonText() const
{
    return ButtonText;
}

void UBRButton::UpdateButtonStyle()
{
    if (bIsDisabled)
    {
        SetColorAndOpacity(ButtonStyle.DisabledColor);
    }
    else
    {
        SetColorAndOpacity(ButtonStyle.NormalColor);
    }

    // 스타일 속성 적용
    FButtonStyle SlateStyle = ButtonStyle.Style;
    SetStyle(SlateStyle);
}

void UBRButton::PlaySound(USoundBase* Sound)
{
    if (Sound && GetWorld())
    {
        UGameplayStatics::PlaySound2D(GetWorld(), Sound);
    }
}