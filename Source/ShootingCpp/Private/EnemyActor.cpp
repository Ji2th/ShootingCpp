// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>
#include "PlayerPawn.h"

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

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyActor::OnBoxCompBeginOverlap);
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	// �¾ ��(BeginPlay) ������ ���ϰ�ʹ�.
	// 30% Ȯ���� �÷��̾����
	// ������ Ȯ���� �չ������� ���ϰ�ʹ�.
	int randValue = FMath::RandRange(0, 9);
	if (randValue < 3) { // 30%
		// ���� = Ÿ�� - ��
		FVector targetLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	
		dir = targetLoc - GetActorLocation();
		dir.Normalize();
	}
	else { // 70%
		dir = GetActorForwardVector();
	}
	// Ctrl + K + C // �ּ��ϱ�
	// Ctrl + K + U // �ּ�Ǯ��
	SetActorRotation(UKismetMathLibrary::MakeRotFromXZ(dir, GetActorUpVector()));

}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ��ư��鼭(Tick) �� �������� �̵��ϰ�ʹ�.
	// P = P0 + v(velocity : dir * speed) * t(�����ǽð�)
	SetActorLocation(GetActorLocation() + dir * speed * DeltaTime);
}

void AEnemyActor::OnBoxCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ε��� ��밡 �÷��̾���
	auto player = Cast<APlayerPawn>(OtherActor);
	if (player != nullptr)
	{
		// ���� VFX�� ���� �÷��̾� ��ġ�� ��ġ�ϰ�ʹ�.
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionFactory, player->GetActorLocation());
		// ���װ�
		player->Destroy();
	}
	// ������
	Destroy();
}

