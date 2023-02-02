#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"

#include "Bird.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TEST_API ABird : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputMappingContext* BirdMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputAction* LookAction;


	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);


private:
	// A capsule pointer
	UPROPERTY(VisibleAnywhere)
		UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* BirdMesh;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* ViewCamera;


};
