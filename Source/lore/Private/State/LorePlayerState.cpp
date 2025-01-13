// Fill out your copyright notice in the Description page of Project Settings.


#include "State/LorePlayerState.h"

#include "AbilitySystem/LoreAbilitySystemComponent.h"
#include "AbilitySystem/LoreAttributeSet.h"

ALorePlayerState::ALorePlayerState()
{
	NetUpdateFrequency = 100.0f;

	AbilitySystemComponent = CreateDefaultSubobject<ULoreAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<ULoreAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ALorePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ALorePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
