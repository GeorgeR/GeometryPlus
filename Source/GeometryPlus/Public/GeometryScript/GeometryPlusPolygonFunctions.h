// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GeometryScript/GeometryScriptTypes.h"
#include "GeometryPlusTypes.h"

#include "GeometryPlusPolygonFunctions.generated.h"

/** Adds to UGeometryScriptLibrary_SimplePolygonFunctions */
UCLASS(meta = (ScriptName = "GeometryPlus_SimplePolygon"))
class GEOMETRYPLUS_API UGeometryPlus_SimplePolygonFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Returns the oriented bounding box of a Simple Polygon
	 */
	UFUNCTION(BlueprintCallable, Category = "GeometryScript|SimplePolygon", meta = (ScriptMethod))
	static FGeometryPlusOrientedBox2 GetOrientedPolygonBounds(const FGeometryScriptSimplePolygon& Polygon);
};
