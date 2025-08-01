// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ANIMTEST_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    // UFUNCTION����������������ڱ༭���б�����
    UFUNCTION(BlueprintCallable, Category = "Child Actor Management")
    static void HideChildActorsInEditor(const AActor* ParentActor);

    UFUNCTION(BlueprintCallable, Category = "Child Actor Management")
    static void ShowChildActorsInEditor(const AActor* ParentActor);
	
};
