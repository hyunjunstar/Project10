// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"
#include "Engine/Engine.h"

void ATestActor::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("TestActor"));

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Green,
            TEXT("TestActor Spawned")
        );
    }
}