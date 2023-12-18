// Fill out your copyright notice in the Description page of Project Settings.

#include "GeometryScript/GeometryPlusTypes.h"

bool FGeometryPlusOrientedBox2::Serialize(FArchive& Ar)
{
	// Serialize normal tagged property data
	if (Ar.IsLoading() || Ar.IsSaving())
	{
		UScriptStruct* const Struct = FGeometryPlusOrientedBox2::StaticStruct();
		Struct->SerializeTaggedProperties(Ar, (uint8*)this, Struct, nullptr);
	}

	Ar	<< Box.Extents
		<< Box.Origin
		<< Box.UnitAxisX;

	return true;
}

FVector2D UGeometryPlus_OrientedBox2Functions::GetOrigin(const FGeometryPlusOrientedBox2& InBox)
{
	return InBox.Box.Origin;
}

FVector2D UGeometryPlus_OrientedBox2Functions::GetUnitAxisX(const FGeometryPlusOrientedBox2& InBox)
{
	return InBox.Box.UnitAxisX;
}

FVector2D UGeometryPlus_OrientedBox2Functions::GetExtents(const FGeometryPlusOrientedBox2& InBox)
{
	return InBox.Box.Extents;
}

bool FGeometryPlusOrientedBox3::Serialize(FArchive& Ar)
{
	// Serialize normal tagged property data
	if (Ar.IsLoading() || Ar.IsSaving())
	{
		UScriptStruct* const Struct = FGeometryPlusOrientedBox2::StaticStruct();
		Struct->SerializeTaggedProperties(Ar, (uint8*)this, Struct, nullptr);
	}

	Ar	<< Box.Extents
		<< Box.Frame.Origin
		<< Box.Frame.Rotation.X
		<< Box.Frame.Rotation.Y
		<< Box.Frame.Rotation.Z
		<< Box.Frame.Rotation.W;

	return true;
}

FVector UGeometryPlus_OrientedBox3Functions::GetOrigin(const FGeometryPlusOrientedBox3& InBox)
{
	return InBox.Box.Frame.Origin;
}

FVector UGeometryPlus_OrientedBox3Functions::GetExtents(const FGeometryPlusOrientedBox3& InBox)
{
	return InBox.Box.Extents;
}

FQuat UGeometryPlus_OrientedBox3Functions::GetRotation(const FGeometryPlusOrientedBox3& InBox)
{
	return FQuat(InBox.Box.Frame.Rotation);
}

bool FGeometryPlusLine2::Serialize(FArchive& Ar)
{
	// Serialize normal tagged property data
	if (Ar.IsLoading() || Ar.IsSaving())
	{
		UScriptStruct* const Struct = FGeometryPlusOrientedBox2::StaticStruct();
		Struct->SerializeTaggedProperties(Ar, (uint8*)this, Struct, nullptr);
	}

	Ar	<< Line.Origin
		<< Line.Direction;

	return true;
}

FGeometryPlusLine2 UGeometryPlus_Line2Functions::MakeLine2(const FVector2D& Origin, const FVector2D& Direction)
{
	return FGeometryPlusLine2({Origin, Direction});
}

void UGeometryPlus_Line2Functions::BreakLine2(const FGeometryPlusLine2& Line, FVector2D& Origin, FVector2D& Direction)
{
	Origin = Line.Line.Origin;
	Direction = Line.Line.Direction;
}

FVector2D UGeometryPlus_Line2Functions::GetOrigin(const FGeometryPlusLine2& InLine)
{
	return InLine.Line.Origin;
}

FVector2D UGeometryPlus_Line2Functions::GetDirection(const FGeometryPlusLine2& InLine)
{
	return InLine.Line.Direction;
}
