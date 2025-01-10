// Fill out your copyright notice in the Description page of Project Settings.


#include "lore/Public/Character/LoreCharacterEnemy.h"


ALoreCharacterEnemy::ALoreCharacterEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void ALoreCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
	
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