// Copyright Your Company, All Rights Reserved.
#include "BRStyleData.h"

FBRButtonStyle::FBRButtonStyle()
    : NormalColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
    , HoveredColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f))
    , PressedColor(FLinearColor(0.9f, 0.9f, 0.9f, 1.0f))
    , DisabledColor(FLinearColor(0.7f, 0.7f, 0.7f, 0.7f))
    , TextColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
    , DisabledTextColor(FLinearColor(0.3f, 0.3f, 0.3f, 1.0f))
    , HoveredSound(nullptr)
    , PressedSound(nullptr)
{
}

UBRStyleData::UBRStyleData()
{
    PrimaryColor = FLinearColor(0.1f, 0.2f, 0.7f, 1.0f);
    SecondaryColor = FLinearColor(0.7f, 0.2f, 0.1f, 1.0f);
    BackgroundColor = FLinearColor(0.05f, 0.05f, 0.05f, 1.0f);
    TextColor = FLinearColor(0.9f, 0.9f, 0.9f, 1.0f);

    DefaultButtonStyle = FBRButtonStyle();

    PrimaryButtonStyle = FBRButtonStyle();
    PrimaryButtonStyle.NormalColor = PrimaryColor;
    PrimaryButtonStyle.HoveredColor = FLinearColor(PrimaryColor.R * 1.1f, PrimaryColor.G * 1.1f, PrimaryColor.B * 1.1f, 1.0f);
    PrimaryButtonStyle.PressedColor = FLinearColor(PrimaryColor.R * 0.9f, PrimaryColor.G * 0.9f, PrimaryColor.B * 0.9f, 1.0f);
    PrimaryButtonStyle.TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

    SecondaryButtonStyle = FBRButtonStyle();
    SecondaryButtonStyle.NormalColor = SecondaryColor;
    SecondaryButtonStyle.HoveredColor = FLinearColor(SecondaryColor.R * 1.1f, SecondaryColor.G * 1.1f, SecondaryColor.B * 1.1f, 1.0f);
    SecondaryButtonStyle.PressedColor = FLinearColor(SecondaryColor.R * 0.9f, SecondaryColor.G * 0.9f, SecondaryColor.B * 0.9f, 1.0f);
    SecondaryButtonStyle.TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

    DangerButtonStyle = FBRButtonStyle();
    DangerButtonStyle.NormalColor = FLinearColor(0.8f, 0.1f, 0.1f, 1.0f);
    DangerButtonStyle.HoveredColor = FLinearColor(0.9f, 0.2f, 0.2f, 1.0f);
    DangerButtonStyle.PressedColor = FLinearColor(0.7f, 0.1f, 0.1f, 1.0f);
    DangerButtonStyle.TextColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

    BackgroundBrush.DrawAs = ESlateBrushDrawType::Box;
    BackgroundBrush.TintColor = BackgroundColor;
}