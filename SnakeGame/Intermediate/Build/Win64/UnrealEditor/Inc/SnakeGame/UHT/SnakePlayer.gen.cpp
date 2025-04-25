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
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer_NoRegister();
SNAKEGAME_API UClass* Z_Construct_UClass_ASpawnableSphere_NoRegister();
UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References

// Begin Class ASnakePlayer Function SpawnSphere
struct Z_Construct_UFunction_ASnakePlayer_SpawnSphere_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakePlayer_SpawnSphere_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakePlayer, nullptr, "SpawnSphere", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakePlayer_SpawnSphere_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakePlayer_SpawnSphere_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakePlayer_SpawnSphere()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakePlayer_SpawnSphere_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakePlayer::execSpawnSphere)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnSphere();
	P_NATIVE_END;
}
// End Class ASnakePlayer Function SpawnSphere

// Begin Class ASnakePlayer
void ASnakePlayer::StaticRegisterNativesASnakePlayer()
{
	UClass* Class = ASnakePlayer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SpawnSphere", &ASnakePlayer::execSpawnSphere },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Movement_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereClass_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tail_MetaData[] = {
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_dirChangeDelay_MetaData[] = {
		{ "Category", "SnakePlayer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Variables\n" },
#endif
		{ "ModuleRelativePath", "SnakePlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Variables" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveForce_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpImpulse_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveScale_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotateScale_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxJumpCount_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Light_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Movement;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SphereClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Tail_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tail;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_dirChangeDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpImpulse;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotateScale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxJumpCount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Light;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASnakePlayer_SpawnSphere, "SpawnSphere" }, // 2983993422
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakePlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Movement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Movement_MetaData), NewProp_Movement_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SphereClass = { "SphereClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, SphereClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASpawnableSphere_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereClass_MetaData), NewProp_SphereClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail_Inner = { "Tail", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ASpawnableSphere_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail = { "Tail", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Tail), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tail_MetaData), NewProp_Tail_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_dirChangeDelay = { "dirChangeDelay", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, dirChangeDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_dirChangeDelay_MetaData), NewProp_dirChangeDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSpeed_MetaData), NewProp_RotationSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveForce = { "MoveForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, MoveForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveForce_MetaData), NewProp_MoveForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_JumpImpulse = { "JumpImpulse", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, JumpImpulse), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpImpulse_MetaData), NewProp_JumpImpulse_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveScale = { "MoveScale", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, MoveScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveScale_MetaData), NewProp_MoveScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotateScale = { "RotateScale", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, RotateScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotateScale_MetaData), NewProp_RotateScale_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MaxJumpCount = { "MaxJumpCount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, MaxJumpCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxJumpCount_MetaData), NewProp_MaxJumpCount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Sphere = { "Sphere", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Sphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sphere_MetaData), NewProp_Sphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x01440000000a000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Light_MetaData), NewProp_Light_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakePlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Movement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SphereClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_dirChangeDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_JumpImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotateScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MaxJumpCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Sphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Camera,
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
	FuncInfo,
	Z_Construct_UClass_ASnakePlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_ASnakePlayer, ASnakePlayer::StaticClass, TEXT("ASnakePlayer"), &Z_Registration_Info_UClass_ASnakePlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakePlayer), 113986836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_2329527977(TEXT("/Script/SnakeGame"),
	Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
