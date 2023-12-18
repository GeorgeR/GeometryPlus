// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeometryPlusTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "GeometryPlusLineFunctions.generated.h"

/** */
UCLASS(meta = (ScriptName = "GeometryPlus_Line"))
class GEOMETRYPLUS_API UGeometryPlusLineFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * 
	 */
	UFUNCTION(BlueprintCallable, Category = "GeometryScript|Line")
	static bool LineLineIntersect2(const FGeometryPlusLine2& LineA, const FGeometryPlusLine2& LineB, FVector2D& Out);
};
