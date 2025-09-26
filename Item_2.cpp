#include "Item_2.h"

AItem_2::AItem_2()
{
	SceneRoot_2 = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot_2"));
	SetRootComponent(SceneRoot_2);

	StaticMeshComp_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh_2"));
	StaticMeshComp_2->SetupAttachment(SceneRoot_2);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Resources/Props/Floor_400x400.Floor_400x400'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp_2->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Resources/Materials/M_Coin_A.M_Coin_A'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp_2->SetMaterial(0, MaterialAsset.Object);
	}


	PrimaryActorTick.bCanEverTick = true;

	LocationSpeed = 20.0f;
}

void AItem_2::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-1000.0f, -1000.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	SetActorScale3D(FVector(1.0f));
}

void AItem_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(LocationSpeed))
	{
		AddActorWorldOffset(FVector(0.0f, 0.0f, LocationSpeed * DeltaTime));
	}
}
