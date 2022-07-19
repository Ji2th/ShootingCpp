// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
AEnemyActor::AEnemyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때(BeginPlay) 방향을 앞방향으로 정하고싶다.
	dir = GetActorForwardVector();
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 살아가면서(Tick) 그 방향으로 이동하고싶다.
	SetActorLocation(GetActorLocation() + dir * speed * DeltaTime);
}

