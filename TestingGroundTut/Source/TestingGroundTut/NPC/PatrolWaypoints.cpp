// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrolWaypoints.h"


// Sets default values for this component's properties
UPatrolWaypoints::UPatrolWaypoints()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Requests an object from the array. Returns nullptr if index is greater than the length of the array, or if the array is empty.
AActor* UPatrolWaypoints::GetWaypoint(int32 index) const {
	if (PatrolPoints.Num() == 0 || index >= PatrolPoints.Num() || index < 0)
		return nullptr;
	
	return PatrolPoints[index];
}

int32 UPatrolWaypoints::GetWaypointCount() const {
	return PatrolPoints.Num();
}



