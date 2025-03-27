// BRButton.cpp
#include "BRButton.h"
#include "Kismet/GameplayStatics.h"

UBRButton::UBRButton()
{
    bPlaySounds = true;
    bIsDisabled = false;
    ButtonStyle = FBRButtonStyle();

    // �⺻ �̺�Ʈ ���ε�
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

        // �������Ʈ �̺�Ʈ ȣ��
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
    // TextBlock�� �����Ƿ� ���⼭�� �ƹ��͵� ���� ����
    // UButton�� �ؽ�Ʈ�� ���� �������� ����
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

    // ��Ÿ�� �Ӽ� ����
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