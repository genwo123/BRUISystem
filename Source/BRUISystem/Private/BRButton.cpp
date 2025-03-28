// Copyright Your Company, All Rights Reserved.
#include "BRButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

UBRButton::UBRButton(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bIsDisabled(false)
    , bPlaySounds(true)
{
    ButtonStyle = FBRButtonStyle();
}

void UBRButton::NativePreConstruct()
{
    Super::NativePreConstruct();

    // �����̳ʿ��� ������ ������ UI ������Ʈ
    UpdateButtonStyle();

    if (TextWidget)
    {
        TextWidget->SetText(ButtonText);
    }
}

void UBRButton::NativeConstruct()
{
    Super::NativeConstruct();

    // ��ư �̺�Ʈ ���ε�
    if (ButtonWidget)
    {
        ButtonWidget->OnClicked.AddDynamic(this, &UBRButton::HandleButtonClicked);
        ButtonWidget->OnHovered.AddDynamic(this, &UBRButton::HandleButtonHovered);
        ButtonWidget->OnUnhovered.AddDynamic(this, &UBRButton::HandleButtonUnhovered);
    }

    // �ؽ�Ʈ ����
    if (TextWidget)
    {
        TextWidget->SetText(ButtonText);
    }

    // ��Ÿ�� ������Ʈ
    UpdateButtonStyle();
}

void UBRButton::NativeDestruct()
{
    // ��ư �̺�Ʈ ���ε� ����
    if (ButtonWidget)
    {
        ButtonWidget->OnClicked.RemoveAll(this);
        ButtonWidget->OnHovered.RemoveAll(this);
        ButtonWidget->OnUnhovered.RemoveAll(this);
    }

    Super::NativeDestruct();
}

void UBRButton::SetButtonText(const FText& InText)
{
    ButtonText = InText;

    if (TextWidget)
    {
        TextWidget->SetText(ButtonText);
    }
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

FText UBRButton::GetButtonText() const
{
    return ButtonText;
}

void UBRButton::HandleButtonClicked()
{
    if (bIsDisabled)
        return;

    // ���� ���
    if (bPlaySounds && ButtonStyle.PressedSound)
    {
        PlaySound(ButtonStyle.PressedSound);
    }

    // �̺�Ʈ ȣ��
    BP_OnButtonClicked();
    OnButtonClicked.Broadcast();
}

void UBRButton::HandleButtonHovered()
{
    if (bIsDisabled)
        return;

    // ���� ���
    if (bPlaySounds && ButtonStyle.HoveredSound)
    {
        PlaySound(ButtonStyle.HoveredSound);
    }

    // �̺�Ʈ ȣ��
    BP_OnButtonHovered();
    OnButtonHovered.Broadcast();
}

void UBRButton::HandleButtonUnhovered()
{
    if (bIsDisabled)
        return;

    // �̺�Ʈ ȣ��
    BP_OnButtonUnhovered();
    OnButtonUnhovered.Broadcast();
}

void UBRButton::UpdateButtonStyle()
{
    if (!ButtonWidget)
        return;

    // ��ư Ȱ��ȭ/��Ȱ��ȭ ���¿� ���� ��Ÿ�� ����
    if (bIsDisabled)
    {
        ButtonWidget->SetColorAndOpacity(ButtonStyle.DisabledColor);
        ButtonWidget->SetIsEnabled(false);

        if (TextWidget)
        {
            TextWidget->SetColorAndOpacity(ButtonStyle.DisabledTextColor);
        }
    }
    else
    {
        ButtonWidget->SetColorAndOpacity(ButtonStyle.NormalColor);
        ButtonWidget->SetIsEnabled(true);

        if (TextWidget)
        {
            TextWidget->SetColorAndOpacity(ButtonStyle.TextColor);
        }
    }
}

void UBRButton::PlaySound(USoundBase* Sound)
{
    if (Sound && GetWorld())
    {
        UGameplayStatics::PlaySound2D(GetWorld(), Sound);
    }
}