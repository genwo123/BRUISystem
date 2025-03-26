// Copyright Your Company, All Rights Reserved.
#include "BRUIFunctionLibrary.h"
#include "BRUISubsystem.h"
#include "BRWidget.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

UBRUISubsystem* UBRUIFunctionLibrary::GetUISubsystem(const UObject* WorldContextObject)
{
    if (!WorldContextObject)
    {
        return nullptr;
    }

    UWorld* World = WorldContextObject->GetWorld();
    if (!World)
    {
        return nullptr;
    }

    UGameInstance* GameInstance = World->GetGameInstance();
    if (!GameInstance)
    {
        return nullptr;
    }

    return GameInstance->GetSubsystem<UBRUISubsystem>();
}

UBRWidget* UBRUIFunctionLibrary::CreateAndPushMainWidget(const UObject* WorldContextObject, TSubclassOf<UBRWidget> WidgetClass)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem)
    {
        return nullptr;
    }

    return UISubsystem->CreateAndPushMainWidget(WidgetClass);
}

UBRWidget* UBRUIFunctionLibrary::CreateAndPushPopupWidget(const UObject* WorldContextObject, TSubclassOf<UBRWidget> WidgetClass)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem)
    {
        return nullptr;
    }

    return UISubsystem->CreateAndPushPopupWidget(WidgetClass);
}

void UBRUIFunctionLibrary::PopMainWidget(const UObject* WorldContextObject)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem)
    {
        return;
    }

    UISubsystem->PopMainWidget();
}

void UBRUIFunctionLibrary::PopPopupWidget(const UObject* WorldContextObject)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem)
    {
        return;
    }

    UISubsystem->PopPopupWidget();
}

void UBRUIFunctionLibrary::ClearMainStack(const UObject* WorldContextObject)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem || !UISubsystem->GetMainStackManager())
    {
        return;
    }

    UISubsystem->GetMainStackManager()->ClearStack();
}

void UBRUIFunctionLibrary::ClearPopupStack(const UObject* WorldContextObject)
{
    UBRUISubsystem* UISubsystem = GetUISubsystem(WorldContextObject);
    if (!UISubsystem || !UISubsystem->GetPopupStackManager())
    {
        return;
    }

    UISubsystem->GetPopupStackManager()->ClearStack();
}

UBRStyleData* UBRUIFunctionLibrary::CreateStyleData()
{
    return NewObject<UBRStyleData>();
}

FSlateBrush UBRUIFunctionLibrary::MakeImageBrush(UTexture2D* Texture, const FVector2D& Size)
{
    FSlateBrush Brush;
    Brush.ImageSize = Size;
    Brush.DrawAs = ESlateBrushDrawType::Image;
    Brush.ImageType = ESlateBrushImageType::FullColor;
    Brush.SetResourceObject(Texture);

    return Brush;
}

FBRButtonStyle UBRUIFunctionLibrary::GetDefaultButtonStyle()
{
    FBRButtonStyle Style;

    return Style;
}

FLinearColor UBRUIFunctionLibrary::GetColorFromHex(const FString& HexString)
{
    FColor Color;
    Color = FColor::FromHex(HexString);

    return FLinearColor(Color);
}