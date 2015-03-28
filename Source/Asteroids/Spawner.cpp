// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroids.h"
#include "Spawner.h"

#define print(code, length, text) if (GEngine) GEngine->AddOnScreenDebugMessage(code, length, FColor::White, text)


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
    for(int i = 3; i < 25; i++){
        wordsMap.Add(i);
        FString string;
        FString path = FPaths::GameDir() + "Words/len" + FString::FromInt(i) + ".txt";
        FFileHelper::LoadFileToString(string, *path);
        TArray<FString> parsed;
        string.ParseIntoArray(&parsed, TEXT("\n"), true);
        wordsMap.Add(i, parsed);
        
        print(i, 3, FString::FromInt(parsed.Num()));
    }
}

//get the list of english dictionary words
//whose long is n
TArray<FString> ASpawner::WordsWithLength(int8 numChars){
    return *(wordsMap.Find(numChars));
}

// Called every frame
void ASpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

