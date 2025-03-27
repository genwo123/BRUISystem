#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UIStackService.generated.h"

class UBRWidget;

UINTERFACE(MinimalAPI)
class UUIStackService : public UInterface
{
    GENERATED_BODY()
};

/**
 * Interface for UI stack services
 */
class BRUISYSTEM_API IUIStackService
{
    GENERATED_BODY()

public:
    // 순수 가상 함수로 정의
    virtual UBRWidget* PushWidget(TSubclassOf<UBRWidget> WidgetClass) = 0;
    virtual void PopWidget() = 0;
    virtual void PopAllWidgets() = 0;
    virtual UBRWidget* ReplaceWidget(TSubclassOf<UBRWidget> WidgetClass) = 0;
    virtual UBRWidget* GetActiveWidget() const = 0;
    virtual TArray<UBRWidget*> GetWidgetStack() const = 0;
};