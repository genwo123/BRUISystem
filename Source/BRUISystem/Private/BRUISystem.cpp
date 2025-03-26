// Copyright Your Company, All Rights Reserved.

#include "BRUISystem.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FBRUISystemModule"

void FBRUISystemModule::StartupModule()
{
    // �÷������� �ε�� �� ����Ǵ� �ڵ�
    UE_LOG(LogTemp, Log, TEXT("BRUISystem ����� ���۵Ǿ����ϴ�."));

    // �÷������� Content ���丮 ��� ��������
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin("BRUISystem");
    if (Plugin.IsValid())
    {
        FString ContentDir = Plugin->GetBaseDir() / TEXT("Content");
        // �ʿ��� ��� ���⼭ Content ���丮���� �ڻ��� �ε��� �� �ֽ��ϴ�
    }
}

void FBRUISystemModule::ShutdownModule()
{
    // �÷������� ��ε�� �� ����Ǵ� �ڵ�
    UE_LOG(LogTemp, Log, TEXT("BRUISystem ����� ����Ǿ����ϴ�."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBRUISystemModule, BRUISystem)