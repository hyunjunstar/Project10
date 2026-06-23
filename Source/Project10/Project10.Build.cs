// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project10 : ModuleRules
{
	public Project10(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		// Private 모듈에서 참조
        PrivateDependencyModuleNames.AddRange(new string[] { "Test", });
    }
}
