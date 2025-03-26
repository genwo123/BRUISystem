// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BRWidget.h"
#include "UIStackService.h"
#include "BRUIStackManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BRUISYSTEM_API UBRUIStackManager : public UObject, public IUIStackService
{
    GENERATED_BODY()

public:
    UBRUIStackManager();

    // IUIStackService 인터페이스 구현
    virtual UBRWidget* PushWidget(TSubclassOf<UBRWidget> WidgetClass) override;
    virtual void PopWidget() override;
    virtual void PopAllWidgets() override;
    virtual UBRWidget* ReplaceWidget(TSubclassOf<UBRWidget> WidgetClass) override;
    virtual UBRWidget* GetActiveWidget() const override;
    virtual TArray<UBRWidget*> GetWidgetStack() const override;

    // 추가 기능
    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    bool PushExistingWidget(UBRWidget* Widget);

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    UBRWidget* PopAndGetWidget();

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    bool RemoveWidget(UBRWidget* Widget);

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    void ClearStack();

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    UBRWidget* GetTopWidget() const;

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    bool HasWidgets() const;

    UFUNCTION(BlueprintCallable, Category = "UI|Stack")
    bool ContainsWidgetOfClass(TSubclassOf<UBRWidget> WidgetClass) const;

private:
    UPROPERTY(Transient)
    TArray<UBRWidget*> WidgetStack;
};