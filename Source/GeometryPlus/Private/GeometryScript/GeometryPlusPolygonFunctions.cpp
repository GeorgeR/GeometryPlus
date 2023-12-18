// Fill out your copyright notice in the Description page of Project Settings.

#include "GeometryScript/GeometryPlusPolygonFunctions.h"

#include "CompGeom/FitOrientedBox2.h"

FGeometryPlusOrientedBox2 UGeometryPlus_SimplePolygonFunctions::GetOrientedPolygonBounds(const FGeometryScriptSimplePolygon& InPolygon)
{
	TConstArrayView<const UE::Math::TVector2<double>> Points = MakeArrayView(*InPolygon.Vertices);

	UE::Geometry::TOrientedBox2<double> OrientedBox = UE::Geometry::FitOrientedBox2Points(Points);
	
	return FGeometryPlusOrientedBox2(MoveTemp(OrientedBox));
}
