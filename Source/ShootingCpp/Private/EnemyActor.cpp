// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AEnemyActor::AEnemyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(boxComp);

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Enemy"));
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	// 태어날 때(BeginPlay) 방향을 정하고싶다.
	// 30% 확률로 플레이어방향
	// 나머지 확률로 앞방향으로 정하고싶다.
	int randValue = FMath::RandRange(0, 9);
	if (randValue < 3) { // 30%
		FVector targetLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		dir = targetLoc - GetActorLocation();
		dir.Normalize();
	}
	else { // 70%
		dir = GetActorForwardVector();
	}
	// Ctrl + K + C // 주석하기
	// Ctrl + K + U // 주석풀기
	SetActorRotation(UKismetMathLibrary::MakeRotFromXZ(dir, GetActorUpVector()));

}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// 살아가면서(Tick) 그 방향으로 이동하고싶다.
	// P = P0 + v(velocity : dir * speed) * t(순간의시간)
	SetActorLocation(GetActorLocation() + dir * speed * DeltaTime);
}

