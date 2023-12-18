// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "OrientedBoxTypes.h"
#include "UObject/Class.h"

#include "GeometryPlusTypes.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "OrientedBox2"))
struct GEOMETRYPLUS_API FGeometryPlusOrientedBox2
{
	GENERATED_BODY()
	
public:
	FGeometryPlusOrientedBox2() = default;

	explicit FGeometryPlusOrientedBox2(const UE::Geometry::FOrientedBox2d& InBox)
		: Box(InBox)
	{
	}

	// Required by TStructOpsTypeTraits interface
	bool operator==(const FGeometryPlusOrientedBox2& Other) const
	{
		return Box.Origin == Other.Box.Origin
			&& Box.Extents == Other.Box.Extents;
	}
	
	bool operator!=(const FGeometryPlusOrientedBox2& Other) const
	{
		return !(*this == Other);
	}

	bool Serialize(FArchive& Ar);

private:
	friend class UGeometryPlus_OrientedBox2Functions;
	
	UE::Geometry::FOrientedBox2d Box;
};

template<>
struct TStructOpsTypeTraits<FGeometryPlusOrientedBox2> : public TStructOpsTypeTraitsBase2<FGeometryPlusOrientedBox2>
{
	enum
	{
		WithIdenticalViaEquality = true,
		WithSerializer = true
	};
};

/** Provides basic data access functions for FGeometryPlusOrientedBox2. */
UCLASS()
class UGeometryPlus_OrientedBox2Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox2")
	static FVector2D GetOrigin(const FGeometryPlusOrientedBox2& Box);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox2")
	static FVector2D GetUnitAxisX(const FGeometryPlusOrientedBox2& Box);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox2")
	static FVector2D GetExtents(const FGeometryPlusOrientedBox2& Box);
};

USTRUCT(BlueprintType, meta = (DisplayName = "OrientedBox3"))
struct GEOMETRYPLUS_API FGeometryPlusOrientedBox3
{
	GENERATED_BODY()
	
public:
	FGeometryPlusOrientedBox3() = default;

	explicit FGeometryPlusOrientedBox3(const UE::Geometry::FOrientedBox3d& InBox)
		: Box(InBox)
	{
	}

	// Required by TStructOpsTypeTraits interface
	bool operator==(const FGeometryPlusOrientedBox3& Other) const
	{
		return Box.Extents == Other.Box.Extents
			&& Box.Frame.Origin == Other.Box.Frame.Origin
			&& Box.Frame.Rotation.EpsilonEqual(Other.Box.Frame.Rotation, UE_KINDA_SMALL_NUMBER);
	}
	
	bool operator!=(const FGeometryPlusOrientedBox3& Other) const
	{
		return !(*this == Other);
	}

	bool Serialize(FArchive& Ar);

private:
	friend class UGeometryPlus_OrientedBox3Functions;
	
	UE::Geometry::FOrientedBox3d Box;
};

template<>
struct TStructOpsTypeTraits<FGeometryPlusOrientedBox3> : public TStructOpsTypeTraitsBase2<FGeometryPlusOrientedBox3>
{
	enum
	{
		WithIdenticalViaEquality = true,
		WithSerializer = true
	};
};

/** Provides basic data access functions for FGeometryPlusOrientedBox3. */
UCLASS()
class UGeometryPlus_OrientedBox3Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox3")
	static FVector GetOrigin(const FGeometryPlusOrientedBox3& Box);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox3")
	static FVector GetExtents(const FGeometryPlusOrientedBox3& Box);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|OrientedBox3")
	static FQuat GetRotation(const FGeometryPlusOrientedBox3& Box);
};

USTRUCT(BlueprintType, meta = (DisplayName = "Line2", HasNativeMake="/Script/GeometryPlus.GeometryPlus_Line2Functions.MakeLine2", HasNativeBreak="/Script/GeometryPlus.GeometryPlus_Line2Functions.BreakLine2"))
struct GEOMETRYPLUS_API FGeometryPlusLine2
{
	GENERATED_BODY()
	
public:
	FGeometryPlusLine2() = default;

	explicit FGeometryPlusLine2(const UE::Geometry::FLine2d& InLine)
		: Line(InLine)
	{
	}

	UE::Geometry::FLine2d& GetValue() { return Line; }

	const UE::Geometry::FLine2d& GetValue() const { return Line; }

	// Required by TStructOpsTypeTraits interface
	bool operator==(const FGeometryPlusLine2& Other) const
	{
		return Line.Origin == Other.Line.Origin
			&& Line.Direction == Other.Line.Direction;
	}
	
	bool operator!=(const FGeometryPlusLine2& Other) const
	{
		return !(*this == Other);
	}

	bool Serialize(FArchive& Ar);

private:
	friend class UGeometryPlus_Line2Functions;
	
	UE::Geometry::FLine2d Line;
};

template<>
struct TStructOpsTypeTraits<FGeometryPlusLine2> : public TStructOpsTypeTraitsBase2<FGeometryPlusLine2>
{
	enum
	{
		WithIdenticalViaEquality = true,
		WithSerializer = true
	};
};

/** Provides basic data access functions for FGeometryPlusOrientedBox2. */
UCLASS()
class UGeometryPlus_Line2Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "GeometryScript|Line2", meta = (NativeMakeFunc))
	static FGeometryPlusLine2 MakeLine2(const FVector2D& Origin, const FVector2D& Direction);

	UFUNCTION(BlueprintPure, Category = "GeometryScript|Line2", meta = (NativeBreakFunc))
	static void BreakLine2(const FGeometryPlusLine2& Line, FVector2D& Origin, FVector2D& Direction);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|Line2")
	static FVector2D GetOrigin(const FGeometryPlusLine2& Line);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GeometryScript|Line2")
	static FVector2D GetDirection(const FGeometryPlusLine2& Line);
};
