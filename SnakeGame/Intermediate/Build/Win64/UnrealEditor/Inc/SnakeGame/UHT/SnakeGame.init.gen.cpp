// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakeGame_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SnakeGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SnakeGame()
	{
		if (!Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SnakeGame",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x725D86DA,
				0x780F5A21,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SnakeGame(Z_Construct_UPackage__Script_SnakeGame, TEXT("/Script/SnakeGame"), Z_Registration_Info_UPackage__Script_SnakeGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x725D86DA, 0x780F5A21));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
