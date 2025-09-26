#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_2.generated.h"

UCLASS()
class SPARTAPROJECT_API AItem_2 : public AActor
{
	GENERATED_BODY()

public:
	AItem_2();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp_2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float LocationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};