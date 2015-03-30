// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS(Blueprintable)
class ASTEROIDS_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
    //get the list of english dictionary words
    //whose long is n
    UFUNCTION(BlueprintCallable, Category="Spawner")
    virtual FString GetRandomWordWithLength(int8 numChars);
    
    //map of english dictionary words
    //mapped according to their length
    TMap<int8, TArray<FString>> wordsMap;
};
