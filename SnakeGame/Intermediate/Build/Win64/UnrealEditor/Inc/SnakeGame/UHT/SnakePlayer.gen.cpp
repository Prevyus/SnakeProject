// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SnakeGame/SnakePlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakePlayer() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer_NoRegister();
UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References

// Begin Class ASnakePlayer
void ASnakePlayer::StaticRegisterNativesASnakePlayer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASnakePlayer);
UClass* Z_Construct_UClass_ASnakePlayer_NoRegister()
{
	return ASnakePlayer::StaticClass();
}
struct Z_Construct_UClass_ASnakePlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SnakePlayer.h" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Light_MetaData[] = {
		{ "Category", "Visuals" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Light;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakePlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Light_MetaData), NewProp_Light_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakePlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakePlayer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASnakePlayer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_SnakeGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakePlayer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASnakePlayer_Statics::ClassParams = {
	&ASnakePlayer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASnakePlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASnakePlayer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASnakePlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_ASnakePlayer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASnakePlayer()
{
	if (!Z_Registration_Info_UClass_ASnakePlayer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASnakePlayer.OuterSingleton, Z_Construct_UClass_ASnakePlayer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASnakePlayer.OuterSingleton;
}
template<> SNAKEGAME_API UClass* StaticClass<ASnakePlayer>()
{
	return ASnakePlayer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASnakePlayer);
ASnakePlayer::~ASnakePlayer() {}
// End Class ASnakePlayer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASnakePlayer, ASnakePlayer::StaticClass, TEXT("ASnakePlayer"), &Z_Registration_Info_UClass_ASnakePlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakePlayer), 627643106U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_3203679096(TEXT("/Script/SnakeGame"),
	Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
