// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "ThirdPersonGuard.h"
#include "BTT_ChooseNextWaypoint.generated.h"

class UPatrolWaypoints;
/**
 * 
 */
UCLASS()
class TESTINGGROUNDTUT_API UBTT_ChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
private:
	void IncrementWaypointIndex(UBlackboardComponent* BlackboardComp, int32 Index, UPatrolWaypoints* WaypointContainerComponent);
	
	void SetBlackboardWaypointValue(UBlackboardComponent* BlackboardComp, AActor* newWaypoint);
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointKey;
};
