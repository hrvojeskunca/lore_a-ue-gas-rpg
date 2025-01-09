// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterPlayer.h"

#include "GameFramework/CharacterMovementComponent.h"


ALoreCharacterPlayer::ALoreCharacterPlayer()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALoreCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();

	SetDefaultCharacterMovement();
}

void ALoreCharacterPlayer::SetDefaultCharacterMovement()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}


