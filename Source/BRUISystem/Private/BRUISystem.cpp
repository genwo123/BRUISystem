// Copyright Your Company, All Rights Reserved.

#include "BRUISystem.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FBRUISystemModule"

void FBRUISystemModule::StartupModule()
{
    // 플러그인이 로드될 때 실행되는 코드
    UE_LOG(LogTemp, Log, TEXT("BRUISystem 모듈이 시작되었습니다."));

    // 플러그인의 Content 디렉토리 경로 가져오기
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin("BRUISystem");
    if (Plugin.IsValid())
    {
        FString ContentDir = Plugin->GetBaseDir() / TEXT("Content");
        // 필요한 경우 여기서 Content 디렉토리에서 자산을 로드할 수 있습니다
    }
}

void FBRUISystemModule::ShutdownModule()
{
    // 플러그인이 언로드될 때 실행되는 코드
    UE_LOG(LogTemp, Log, TEXT("BRUISystem 모듈이 종료되었습니다."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBRUISystemModule, BRUISystem)