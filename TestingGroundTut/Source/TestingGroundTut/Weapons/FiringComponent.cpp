// Fill out your copyright notice in the Description page of Project Settings.

#include "FiringComponent.h"
#include "Engine/World.h"
#include "BallProjectile.h"


// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UFiringComponent::Fire() {

	UWorld* const World = GetWorld();
	if (World != NULL) {

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		auto SpawnTransform = GetComponentTransform();

		World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnTransform.GetLocation(), SpawnTransform.GetRotation().Rotator(), ActorSpawnParams);
	}
}



