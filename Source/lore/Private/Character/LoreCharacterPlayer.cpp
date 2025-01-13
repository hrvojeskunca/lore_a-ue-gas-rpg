// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterPlayer.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "State/LorePlayerState.h"


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

void ALoreCharacterPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

void ALoreCharacterPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
	
}

void ALoreCharacterPlayer::InitAbilityActorInfo()
{
	if (ALorePlayerState* LorePlayerState = GetPlayerState<ALorePlayerState>())
	{
		LorePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(LorePlayerState, this);
		AbilitySystemComponent = LorePlayerState->GetAbilitySystemComponent();
		AttributeSet = LorePlayerState->GetAttributeSet();
	}
}



