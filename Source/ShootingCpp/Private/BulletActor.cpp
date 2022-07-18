// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	// 박스를 루트로
	SetRootComponent(boxComp);
	// 외관을 박스의 자식으로 하고싶다.
	meshComp->SetupAttachment(boxComp);

	boxComp->SetBoxExtent(FVector(37.5f, 12.5f, 50));
	meshComp->SetRelativeScale3D(FVector(0.75f, 0.25f, 1));
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
	// 1. 앞 방향을 만들고
	FVector dir = GetActorForwardVector();
	FVector p0 = GetActorLocation();
	// 2. 그 방향으로 이동하고싶다. (P = P0 + vt)
	SetActorLocation(p0 + dir * speed * DeltaTime);

}

