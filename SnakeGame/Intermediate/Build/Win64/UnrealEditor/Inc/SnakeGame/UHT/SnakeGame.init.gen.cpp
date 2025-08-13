// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakeGame_init() {}
	SNAKEGAME_API UFunction* Z_Construct_UDelegateFunction_SnakeGame_OnAppleEaten__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SnakeGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SnakeGame()
	{
		if (!Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SnakeGame_OnAppleEaten__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SnakeGame",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x40550E99,
				0x2F924C64,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SnakeGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SnakeGame(Z_Construct_UPackage__Script_SnakeGame, TEXT("/Script/SnakeGame"), Z_Registration_Info_UPackage__Script_SnakeGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x40550E99, 0x2F924C64));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
