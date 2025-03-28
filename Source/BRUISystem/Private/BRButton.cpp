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

    // 디자이너에서 편집된 값으로 UI 업데이트
    UpdateButtonStyle();

    if (TextWidget)
    {
        TextWidget->SetText(ButtonText);
    }
}

void UBRButton::NativeConstruct()
{
    Super::NativeConstruct();

    // 버튼 이벤트 바인딩
    if (ButtonWidget)
    {
        ButtonWidget->OnClicked.AddDynamic(this, &UBRButton::HandleButtonClicked);
        ButtonWidget->OnHovered.AddDynamic(this, &UBRButton::HandleButtonHovered);
        ButtonWidget->OnUnhovered.AddDynamic(this, &UBRButton::HandleButtonUnhovered);
    }

    // 텍스트 설정
    if (TextWidget)
    {
        TextWidget->SetText(ButtonText);
    }

    // 스타일 업데이트
    UpdateButtonStyle();
}

void UBRButton::NativeDestruct()
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

    // 사운드 재생
    if (bPlaySounds && ButtonStyle.PressedSound)
    {
        PlaySound(ButtonStyle.PressedSound);
    }

    // 이벤트 호출
    BP_OnButtonClicked();
    OnButtonClicked.Broadcast();
}

void UBRButton::HandleButtonHovered()
{
    if (bIsDisabled)
        return;

    // 사운드 재생
    if (bPlaySounds && ButtonStyle.HoveredSound)
    {
        PlaySound(ButtonStyle.HoveredSound);
    }

    // 이벤트 호출
    BP_OnButtonHovered();
    OnButtonHovered.Broadcast();
}

void UBRButton::HandleButtonUnhovered()
{
    if (bIsDisabled)
        return;

    // 이벤트 호출
    BP_OnButtonUnhovered();
    OnButtonUnhovered.Broadcast();
}

void UBRButton::UpdateButtonStyle()
{
    if (!ButtonWidget)
        return;

    // 버튼 활성화/비활성화 상태에 따라 스타일 적용
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