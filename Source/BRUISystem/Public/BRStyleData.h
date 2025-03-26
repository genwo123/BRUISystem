// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Styling/SlateTypes.h"
#include "BRStyleData.generated.h"

USTRUCT(BlueprintType)
struct BRUISYSTEM_API FBRButtonStyle
{
    GENERATED_USTRUCT_BODY()

    FBRButtonStyle();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor NormalColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor HoveredColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor PressedColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor DisabledColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor TextColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FLinearColor DisabledTextColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FButtonStyle Style;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    FButtonStyle DisabledStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    class USoundBase* HoveredSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Style")
    class USoundBase* PressedSound;
};

UCLASS(BlueprintType, Blueprintable)
class BRUISYSTEM_API UBRStyleData : public UObject
{
    GENERATED_BODY()

public:
    UBRStyleData();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FBRButtonStyle DefaultButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FBRButtonStyle PrimaryButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FBRButtonStyle SecondaryButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FBRButtonStyle DangerButtonStyle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FLinearColor PrimaryColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FLinearColor SecondaryColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FLinearColor BackgroundColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FLinearColor TextColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Style")
    FSlateBrush BackgroundBrush;
};