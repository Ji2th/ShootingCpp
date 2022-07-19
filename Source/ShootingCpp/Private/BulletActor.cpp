// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include "EnemyActor.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	// �ڽ��� ��Ʈ��
	SetRootComponent(boxComp);
	// �ܰ��� �ڽ��� �ڽ����� �ϰ�ʹ�.
	meshComp->SetupAttachment(boxComp);

	boxComp->SetBoxExtent(FVector(37.5f, 12.5f, 50));
	meshComp->SetRelativeScale3D(FVector(0.75f, 0.25f, 1));

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Bullet"));
	/*
	boxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	// Ctrl + K + D �ڵ� �鿩����
	// Ctrl + K + C �ּ��ϱ�
	// Ctrl + K + U �ּ�Ǯ��
//ECC_GameTraceChannel1: Player
//ECC_GameTraceChannel2 : Bullet
//ECC_GameTraceChannel3 : Enemy
//ECC_GameTraceChannel4 : DestroyZone

	boxComp->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel2);

	boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	boxComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECR_Overlap);
	boxComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECR_Overlap);
	*/
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 1. �� ������ �����
	FVector dir = GetActorForwardVector();
	FVector p0 = GetActorLocation();
	// 2. �� �������� �̵��ϰ�ʹ�. (P = P0 + vt)
	SetActorLocation(p0 + dir * speed * DeltaTime);
}

void ABulletActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	AEnemyActor* enemy = Cast<AEnemyActor>(OtherActor);
	if (enemy != nullptr)
	{
		// ���װ�
		enemy->Destroy();
	}else{
	}
	
	// ������
	Destroy();
}

