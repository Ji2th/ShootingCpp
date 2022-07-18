// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Components/BoxComponent.h>

// Sets default values
APlayerPawn::APlayerPawn()
{

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �浹ü�� �����ϰ� ��Ʈ������Ʈ�� �����ϰ�ʹ�.
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);

	// �ܰ��� ����� Static Mesh Component�� �����ϰ�ʹ�.
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));

	// meshComp�� Root�� ���̰�ʹ�.
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("%f"), h);

	// 1. ������� �Է��� �ް�
	// 2. �� �Է°����� ������ �����
	FVector dir = FVector(0, h, v);
	dir.Normalize(); // ������ ���̸� 1�� �����ʹ�.
	// 3. �� �������� �̵��ϰ�ʹ�.
	// P = P0 + vt;
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * DeltaTime;
	SetActorLocation(P0 + vt);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &APlayerPawn::OnAxisHorizontal);

	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &APlayerPawn::OnAxisVertical);
}

void APlayerPawn::OnAxisHorizontal(float value)
{
	h = value;
}

void APlayerPawn::OnAxisVertical(float value)
{
	v = value;
}

