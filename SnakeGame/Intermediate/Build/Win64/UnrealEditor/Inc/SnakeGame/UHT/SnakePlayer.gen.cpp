// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SnakeGame/SnakePlayer.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSnakePlayer() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer();
SNAKEGAME_API UClass* Z_Construct_UClass_ASnakePlayer_NoRegister();
SNAKEGAME_API UClass* Z_Construct_UClass_ASpawnableSphere_NoRegister();
UPackage* Z_Construct_UPackage__Script_SnakeGame();
// End Cross Module References

// Begin Class ASnakePlayer Function OnBeginOverlap
struct Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics
{
	struct SnakePlayer_eventOnBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComp;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePlayer_eventOnBeginOverlap_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComp_MetaData), NewProp_OverlappedComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePlayer_eventOnBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePlayer_eventOnBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePlayer_eventOnBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((SnakePlayer_eventOnBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SnakePlayer_eventOnBeginOverlap_Parms), &Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SnakePlayer_eventOnBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OverlappedComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakePlayer, nullptr, "OnBeginOverlap", nullptr, nullptr, Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::SnakePlayer_eventOnBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::SnakePlayer_eventOnBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakePlayer::execOnBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnBeginOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class ASnakePlayer Function OnBeginOverlap

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

// Begin Class ASnakePlayer Function SpawnSpheres
struct Z_Construct_UFunction_ASnakePlayer_SpawnSpheres_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASnakePlayer_SpawnSpheres_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASnakePlayer, nullptr, "SpawnSpheres", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASnakePlayer_SpawnSpheres_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASnakePlayer_SpawnSpheres_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ASnakePlayer_SpawnSpheres()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASnakePlayer_SpawnSpheres_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ASnakePlayer::execSpawnSpheres)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnSpheres();
	P_NATIVE_END;
}
// End Class ASnakePlayer Function SpawnSpheres

// Begin Class ASnakePlayer
void ASnakePlayer::StaticRegisterNativesASnakePlayer()
{
	UClass* Class = ASnakePlayer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnBeginOverlap", &ASnakePlayer::execOnBeginOverlap },
		{ "SpawnSphere", &ASnakePlayer::execSpawnSphere },
		{ "SpawnSpheres", &ASnakePlayer::execSpawnSpheres },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isPlayer_MetaData[] = {
		{ "Category", "SnakePlayer" },
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
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveForce_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GrowAmount_MetaData[] = {
		{ "Category", "SnakePlayer" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Sphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collider_MetaData[] = {
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SnakePlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Movement;
	static void NewProp_isPlayer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isPlayer;
	static const UECodeGen_Private::FClassPropertyParams NewProp_SphereClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Tail_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Tail;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_dirChangeDelay;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotateScale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GrowAmount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Sphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collider;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Light;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ASnakePlayer_OnBeginOverlap, "OnBeginOverlap" }, // 2317193862
		{ &Z_Construct_UFunction_ASnakePlayer_SpawnSphere, "SpawnSphere" }, // 2983993422
		{ &Z_Construct_UFunction_ASnakePlayer_SpawnSpheres, "SpawnSpheres" }, // 3809038561
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASnakePlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Movement = { "Movement", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Movement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Movement_MetaData), NewProp_Movement_MetaData) };
void Z_Construct_UClass_ASnakePlayer_Statics::NewProp_isPlayer_SetBit(void* Obj)
{
	((ASnakePlayer*)Obj)->isPlayer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_isPlayer = { "isPlayer", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASnakePlayer), &Z_Construct_UClass_ASnakePlayer_Statics::NewProp_isPlayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isPlayer_MetaData), NewProp_isPlayer_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SphereClass = { "SphereClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, SphereClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASpawnableSphere_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereClass_MetaData), NewProp_SphereClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail_Inner = { "Tail", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ASpawnableSphere_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail = { "Tail", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Tail), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tail_MetaData), NewProp_Tail_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_dirChangeDelay = { "dirChangeDelay", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, dirChangeDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_dirChangeDelay_MetaData), NewProp_dirChangeDelay_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, RotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationSpeed_MetaData), NewProp_RotationSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveForce = { "MoveForce", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, MoveForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveForce_MetaData), NewProp_MoveForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveScale = { "MoveScale", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, MoveScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveScale_MetaData), NewProp_MoveScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotateScale = { "RotateScale", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, RotateScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotateScale_MetaData), NewProp_RotateScale_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_GrowAmount = { "GrowAmount", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, GrowAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GrowAmount_MetaData), NewProp_GrowAmount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Sphere = { "Sphere", nullptr, (EPropertyFlags)0x01440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Sphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Sphere_MetaData), NewProp_Sphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Collider = { "Collider", nullptr, (EPropertyFlags)0x014400000008001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Collider), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collider_MetaData), NewProp_Collider_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x01440000000a000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Light_MetaData), NewProp_Light_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASnakePlayer, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneComponent_MetaData), NewProp_SceneComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASnakePlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Movement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_isPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SphereClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Tail,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_dirChangeDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotationSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_MoveScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_RotateScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_GrowAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Sphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Collider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_Light,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASnakePlayer_Statics::NewProp_SceneComponent,
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
		{ Z_Construct_UClass_ASnakePlayer, ASnakePlayer::StaticClass, TEXT("ASnakePlayer"), &Z_Registration_Info_UClass_ASnakePlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASnakePlayer), 2006318584U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_1974227491(TEXT("/Script/SnakeGame"),
	Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_SantiagoValeraRocha_Desktop_Assignments_C___Unreal_Engine_Snake_Assignment_SnakeProject_SnakeGame_Source_SnakeGame_SnakePlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
