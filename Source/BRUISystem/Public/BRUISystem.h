// Copyright Your Company, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class BRUISYSTEM_API FBRUISystemModule : public IModuleInterface
{
public:
    /** IModuleInterface 구현 */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    /** 모듈 인스턴스 가져오기 */
    static FBRUISystemModule& Get()
    {
        return FModuleManager::LoadModuleChecked<FBRUISystemModule>("BRUISystem");
    }

    /** 모듈이 로드되었는지 확인 */
    static bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("BRUISystem");
    }
};