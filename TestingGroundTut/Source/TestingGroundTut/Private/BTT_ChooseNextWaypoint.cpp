// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/BTT_ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolWaypoints.h"

EBTNodeResult::Type UBTT_ChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto WaypointContainerComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolWaypoints>();
	if(!ensure(WaypointContainerComponent)) { return EBTNodeResult::Failed; }

	auto newWaypoint = WaypointContainerComponent->GetWaypoint(Index);
	if (!ensure(newWaypoint)) { return EBTNodeResult::Failed; }

	SetBlackboardWaypointValue(BlackboardComp, newWaypoint);

	IncrementWaypointIndex(BlackboardComp, Index, WaypointContainerComponent);

	return EBTNodeResult::Succeeded;
}

void UBTT_ChooseNextWaypoint::SetBlackboardWaypointValue(UBlackboardComponent* BlackboardComp, AActor* newWaypoint) {
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, newWaypoint);
}

void UBTT_ChooseNextWaypoint::IncrementWaypointIndex(UBlackboardComponent* BlackboardComp, int32 Index, UPatrolWaypoints* WaypointContainerComponent) {
	auto newIndex = (Index + 1) % WaypointContainerComponent->GetWaypointCount();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, newIndex);
}


