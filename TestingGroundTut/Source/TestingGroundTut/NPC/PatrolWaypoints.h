// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolWaypoints.generated.h"

/**
*	Container for waypoints.
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDTUT_API UPatrolWaypoints : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolWaypoints();

	AActor* GetWaypoint(int32 index) const;

	int32 GetWaypointCount() const;

protected:

	UPROPERTY(EditInstanceOnly, Category = "Default")
		TArray<AActor*> PatrolPoints;
	
};
