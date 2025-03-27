// Copyright Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;
using System.IO;

public class BRUISystem : ModuleRules
{
    public BRUISystem(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // 명시적 경로 추가
        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Public")
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Private")
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "UMG",
                "Slate",
                "SlateCore",
                // ... add other public dependencies that you statically link with here ...
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "RenderCore",
                "GameplayTags",
                "Projects",  // IPluginManager를 사용하기 위해 추가
                "NetCore",   // 네트워크 기능 지원을 위해 추가
                // ... add private dependencies that you statically link with here ...    
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...
            }
        );

        // 모듈이 런타임에 확실히 로드되도록 정의 추가
        PublicDefinitions.Add("WITH_BRUISYSTEM=1");

        // 블루프린트에서 사용 가능하도록 설정
        bLegacyPublicIncludePaths = false;
        OptimizeCode = CodeOptimization.Never;
    }
}