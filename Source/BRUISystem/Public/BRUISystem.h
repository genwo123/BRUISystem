// Copyright Your Company, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class BRUISYSTEM_API FBRUISystemModule : public IModuleInterface
{
public:
    /** IModuleInterface ���� */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    /** ��� �ν��Ͻ� �������� */
    static FBRUISystemModule& Get()
    {
        return FModuleManager::LoadModuleChecked<FBRUISystemModule>("BRUISystem");
    }

    /** ����� �ε�Ǿ����� Ȯ�� */
    static bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("BRUISystem");
    }
};