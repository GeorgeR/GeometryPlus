// Fill out your copyright notice in the Description page of Project Settings.

#include "GeometryScript/GeometryPlusLineFunctions.h"

bool UGeometryPlusLineFunctions::LineLineIntersect2(const FGeometryPlusLine2& LineA, const FGeometryPlusLine2& LineB, FVector2D& Out)
{
	return LineA.GetValue().IntersectionPoint(LineB.GetValue(), Out);
}
