// Copyright Your Company, All Rights Reserved.
#include "BRUISystem.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FBRUISystemModule"

void FBRUISystemModule::StartupModule()
{
    UE_LOG(LogTemp, Log, TEXT("BRUISystem: Module started"));
}

void FBRUISystemModule::ShutdownModule()
{
    UE_LOG(LogTemp, Log, TEXT("BRUISystem: Module shutdown"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBRUISystemModule, BRUISystem)