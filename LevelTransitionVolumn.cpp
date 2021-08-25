// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelTransitionVolumn.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "Main.h"

// Sets default values
ALevelTransitionVolumn::ALevelTransitionVolumn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TransitionVolumn = CreateDefaultSubobject<UBoxComponent>(TEXT("TransitionVolumn"));
	RootComponent = TransitionVolumn;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(GetRootComponent());

	TransitionLevelName = "SunTemple";

}

// Called when the game starts or when spawned
void ALevelTransitionVolumn::BeginPlay()
{
	Super::BeginPlay();

	TransitionVolumn->OnComponentBeginOverlap.AddDynamic(this, &ALevelTransitionVolumn::OnOverlapBegin);
	
}

// Called every frame
void ALevelTransitionVolumn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALevelTransitionVolumn::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			Main->SwitchLevel(TransitionLevelName);
		}
	}
}

void ALevelTransitionVolumn::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}



