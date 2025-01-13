// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterBase.h"


ALoreCharacterBase::ALoreCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponComponent = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	WeaponComponent->SetupAttachment(GetMesh(), FName(TEXT("LeftHand_WeaponSocket")));
	WeaponComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ALoreCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* ALoreCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ALoreCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}
