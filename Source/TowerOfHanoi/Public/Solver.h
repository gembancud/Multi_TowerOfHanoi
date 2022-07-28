// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Solver.generated.h"

USTRUCT(BlueprintType)
struct FInstruction
{
	GENERATED_BODY()

	FInstruction()
	{
	}

	FInstruction(int disk, FString startPeg, FString endPeg)
	{
		Disk = disk;
		StartPeg = startPeg;
		EndPeg = endPeg;
	}

	UPROPERTY(BlueprintReadOnly)
	int32 Disk;

	UPROPERTY(BlueprintReadOnly)
	FString StartPeg;

	UPROPERTY(BlueprintReadOnly)
	FString EndPeg;
};

/**
 * 
 */
UCLASS()
class TOWEROFHANOI_API USolver : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="TOH BPFL")
	static TArray<FInstruction> TOH_Solve(int numDisk, FString LeftPegName, FString CenterPegName, FString RightPegName);

private:
	static void GenerateInstructions(TArray<FInstruction> &Instructions,int numDisk, FString LeftPegName, FString CenterPegName, FString RightPegName);
};
