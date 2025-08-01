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
    // UFUNCTION宏让这个函数可以在编辑器中被调用
    UFUNCTION(BlueprintCallable, Category = "Child Actor Management")
    static void HideChildActorsInEditor(const AActor* ParentActor);

    UFUNCTION(BlueprintCallable, Category = "Child Actor Management")
    static void ShowChildActorsInEditor(const AActor* ParentActor);
	
};
