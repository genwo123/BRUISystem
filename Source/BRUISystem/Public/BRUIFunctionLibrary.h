// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BRStyleData.h"
#include "BRUIFunctionLibrary.generated.h"

UCLASS()
class BRUISYSTEM_API UBRUIFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static class UBRUISubsystem* GetUISubsystem(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static class UBRWidget* CreateAndPushMainWidget(const UObject* WorldContextObject, TSubclassOf<UBRWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static class UBRWidget* CreateAndPushPopupWidget(const UObject* WorldContextObject, TSubclassOf<UBRWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static void PopMainWidget(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static void PopPopupWidget(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static void ClearMainStack(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility", meta = (WorldContext = "WorldContextObject"))
    static void ClearPopupStack(const UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "UI|Utility")
    static UBRStyleData* CreateStyleData();

    UFUNCTION(BlueprintPure, Category = "UI|Utility")
    static FSlateBrush MakeImageBrush(UTexture2D* Texture, const FVector2D& Size);

    UFUNCTION(BlueprintPure, Category = "UI|Utility")
    static FBRButtonStyle GetDefaultButtonStyle();

    UFUNCTION(BlueprintPure, Category = "UI|Utility")
    static FLinearColor GetColorFromHex(const FString& HexString);
};