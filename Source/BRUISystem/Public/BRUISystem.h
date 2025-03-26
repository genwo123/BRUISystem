// Copyright Your Company, All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBRUISystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    static inline FBRUISystemModule& Get()
    {
        return FModuleManager::LoadModuleChecked<FBRUISystemModule>("BRUISystem");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("BRUISystem");
    }
};