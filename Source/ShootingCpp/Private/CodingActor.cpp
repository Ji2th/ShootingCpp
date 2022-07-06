// Fill out your copyright notice in the Description page of Project Settings.


#include "CodingActor.h"

// Sets default values
ACodingActor::ACodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	number = 10;
	UE_LOG(LogTemp, Warning, TEXT("%d"), number);

	fNumber = 3.14f;
	UE_LOG(LogTemp, Warning, TEXT("%f"), fNumber);

	myName = TEXT("이영훈");
	UE_LOG(LogTemp, Warning, TEXT("%s"), *myName);

	bGood = false;
	UE_LOG(LogTemp, Warning, TEXT("%d"), bGood);
	
}

// Called when the game starts or when spawned
void ACodingActor::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ACodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

