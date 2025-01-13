// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterEnemy.h"

#include "AbilitySystem/LoreAbilitySystemComponent.h"
#include "AbilitySystem/LoreAttributeSet.h"


ALoreCharacterEnemy::ALoreCharacterEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<ULoreAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<ULoreAttributeSet>("AttributeSet");
}

void ALoreCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
}


void ALoreCharacterEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CustomDepthStencilRed);
	WeaponComponent->SetRenderCustomDepth(true);
	WeaponComponent->SetCustomDepthStencilValue(CustomDepthStencilRed);

}

void ALoreCharacterEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	WeaponComponent->SetRenderCustomDepth(false);
}