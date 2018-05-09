// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ChildActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "../Weapons/FPS_GunBasic.h"
#include "Engine/World.h"
#include "Animation/AnimInstance.h"


// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPCamera->SetupAttachment(GetCapsuleComponent());
	FPCamera->RelativeLocation = FVector(-10.57f, 7.23f, 63.34f); // Position the camera
	FPCamera->bUsePawnControlRotation = true;

	FPArms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPArmsMesh"));
	FPArms->SetupAttachment(FPCamera);
	FPArms->RelativeLocation = FVector(3.29f, -5.f, -161.33f);
	FPArms->RelativeRotation = FRotator(1.9f, -19.2f, 5.2f);
	FPArms->bCastDynamicShadow = false;
	FPArms->CastShadow = false;
	FPArms->bOnlyOwnerSee = true;


}

// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if(!GunBlueprint) {
		UE_LOG(LogTemp, Error, TEXT("Gun blueprint is missing from character."))
		return;
	}

	Gun = GetWorld()->SpawnActor<AFPS_GunBasic>(GunBlueprint);
	Gun->AttachToComponent(FPArms, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance = GetMesh()->GetAnimInstance();

	if(InputComponent != nullptr) {
		InputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::PullTrigger);
	}
	
}

void AMannequin::PullTrigger()
{
	if (!Gun) { return; }

	Gun->OnFire();
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

