// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerOfHanoi/Public/Solver.h"

 TArray<FInstruction> USolver::TOH_Solve(int numDisk, FString LeftPegName, FString CenterPegName,
                                        FString RightPegName)
{
	TArray<FInstruction> Instructions;
	GenerateInstructions(Instructions, numDisk, LeftPegName, CenterPegName, RightPegName);
	return Instructions;
}

 void USolver::GenerateInstructions(TArray<FInstruction>& Instructions, int numDisk, FString LeftPegName,
                                   FString CenterPegName, FString RightPegName)
{
	if (numDisk == 0)
	{
		return;
		// Instructions.Add(FInstruction(numDisk, LeftPegName, RightPegName));
	}
	else
	{
		GenerateInstructions(Instructions, numDisk - 1, LeftPegName, RightPegName, CenterPegName);

		Instructions.Add(FInstruction(numDisk, LeftPegName, RightPegName));

		GenerateInstructions(Instructions, numDisk - 1, CenterPegName, LeftPegName, RightPegName);
	}
}
