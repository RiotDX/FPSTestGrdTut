// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "ThirdPersonGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDTUT_API AThirdPersonGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category = "Default")
		TArray<AActor*> PatrolPointsCPP;
	
	
	
};
