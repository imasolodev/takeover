// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Takeover : ModuleRules
{
	public Takeover(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
