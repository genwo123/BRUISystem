#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IUIStateHandler.generated.h"

UINTERFACE(MinimalAPI)
class UIUIStateHandler : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for objects that can handle UI state changes
 */
class BRUISYSTEM_API IIUIStateHandler
{
	GENERATED_BODY()

public:
	// 가상 함수로 정의 - 블루프린트 이벤트 제거
	virtual void OnUIStateEnter(const FName& StateName) = 0;
	virtual void OnUIStateExit(const FName& StateName) = 0;
	virtual bool CanEnterUIState(const FName& StateName) = 0;
};