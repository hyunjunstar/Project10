// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Project10EditorTarget : TargetRules
{
	public Project10EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
		//ExtraModuleNames.Add("Project10");
		// Test 모듈 추가
		ExtraModuleNames.AddRange(new string[]
		{
			"Project10", 
			"Test", 
		});
	}
}
