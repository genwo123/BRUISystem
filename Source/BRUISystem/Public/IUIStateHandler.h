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
	// ���� �Լ��� ���� - �������Ʈ �̺�Ʈ ����
	virtual void OnUIStateEnter(const FName& StateName) = 0;
	virtual void OnUIStateExit(const FName& StateName) = 0;
	virtual bool CanEnterUIState(const FName& StateName) = 0;
};