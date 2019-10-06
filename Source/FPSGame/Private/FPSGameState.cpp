// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameState.h"
#include "FPSPlayerController.h"


void AFPSGameState::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionSuccess)
{
	// FConstPawnIterator It = GetWorld()->GetPawnIterator();
	// for (It; It; It++)
	// {
	// 	APawn* Pawn = It->Get();
	// 	if (Pawn && Pawn->IsLocallyControlled())
	// 	{
	// 		Pawn->DisableInput(nullptr);
	// 	}
	// }

	FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator();
	for (It; It; It++)
	{
		AFPSPlayerController* PC = Cast<AFPSPlayerController>(It->Get());
		if (PC && PC->IsLocalController())
		{
			PC->OnMissionCompleted(InstigatorPawn, bMissionSuccess);

			// Disable input
			APawn* MyPawn = PC->GetPawn();
			if (MyPawn)
			{
				MyPawn->DisableInput(PC);
			}
		}
	}
}
