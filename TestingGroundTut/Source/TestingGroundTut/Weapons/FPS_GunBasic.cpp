// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_GunBasic.h"
#include "Kismet/GameplayStatics.h"
#include "BallProjectile.h"
#include "Engine/World.h"


// Sets default values
AFPS_GunBasic::AFPS_GunBasic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

}

// Called when the game starts or when spawned
void AFPS_GunBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_GunBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPS_GunBasic::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			//if (bUsingMotionControllers)
			//{
			//	const FRotator SpawnRotation = VR_MuzzleLocation->GetComponentRotation();
			//	const FVector SpawnLocation = VR_MuzzleLocation->GetComponentLocation();
			//	World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
			//}
			//else
			//{
			const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			World->SpawnActor<ABallProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			//}
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

