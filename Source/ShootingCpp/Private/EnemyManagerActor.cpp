// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManagerActor.h"
#include <Components/ArrowComponent.h>
#include "EnemyActor.h"

// Sets default values
AEnemyManagerActor::AEnemyManagerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	arrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("arrowComp"));
	arrowComp->SetRelativeRotation(FRotator(-90, 0, 180));
	arrowComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyManagerActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle timerHanleMakeEnemy;
	GetWorldTimerManager().SetTimer(timerHanleMakeEnemy, this, &AEnemyManagerActor::MakeEnemy, makeTime, true);
}

// Called every frame
void AEnemyManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	// 1. �ð��� �帣�ٰ�(����ð��� DeltaTime�� �����ϴٰ�)
	currentTime += DeltaTime;
	// 2. ���� ����ð� > �����ð� ���
	if (currentTime > makeTime)
	{
		// 3. MekeEnemy�Լ��� ȣ���ϰ�ʹ�.
		MakeEnemy();
		// 4. ����ð��� 0���� �ʱ�ȭ �ϰ�ʹ�.
		currentTime = 0;
	}
	*/
}

void AEnemyManagerActor::MakeEnemy()
{
	// �����忡�� ���� ���� arrowComp�� ��ġ�ϰ�ʹ�.
	GetWorld()->SpawnActor<AEnemyActor>(enemyFactory, arrowComp->GetComponentTransform());
}

