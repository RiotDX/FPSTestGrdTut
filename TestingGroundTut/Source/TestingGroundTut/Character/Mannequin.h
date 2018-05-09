// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mannequin.generated.h"

class UChildActorComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class AFPS_GunBasic;

UCLASS()
class TESTINGGROUNDTUT_API AMannequin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMannequin();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Inherited)
		TSubclassOf<class AFPS_GunBasic> GunBlueprint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = Inherited)
		UCameraComponent* FPCamera = nullptr;
	UPROPERTY(VisibleDefaultsOnly, Category = Inherited)
		USkeletalMeshComponent* FPArms = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inherited, meta = (AllowPrivateAccess = "true"))
		AFPS_GunBasic* Gun = nullptr;

private:	
	
	UFUNCTION(BlueprintCallable, Category = FPS)
		void PullTrigger();
};
