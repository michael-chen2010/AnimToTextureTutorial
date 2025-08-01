// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"


void UMyBlueprintFunctionLibrary::HideChildActorsInEditor(const AActor* ParentActor)
{
    // 获取所有附加的子Actor
    TArray<AActor*> AttachedActors;
    ParentActor->GetAttachedActors(AttachedActors);

    // 遍历所有子Actor并隐藏它们
    for (AActor* ChildActor : AttachedActors)
    {
        if (ChildActor)
        {
            ChildActor->SetHidden(true);
            ChildActor->bHiddenEd = true;
            ChildActor->SetIsTemporarilyHiddenInEditor(true);

			ChildActor->SetActorHiddenInGame(true); // 如果需要在游戏中也隐藏，可以添加这一行
        }
    }

    // 打印日志以确认操作
    UE_LOG(LogTemp, Warning, TEXT("Hid %d child actors in editor."), AttachedActors.Num());
}

void UMyBlueprintFunctionLibrary::ShowChildActorsInEditor(const AActor* ParentActor)
{
    // 获取所有附加的子Actor
    TArray<AActor*> AttachedActors;
    ParentActor->GetAttachedActors(AttachedActors);

    // 遍历所有子Actor并显示它们
    for (AActor* ChildActor : AttachedActors)
    {
        if (ChildActor)
        {
            ChildActor->SetHidden(false);
            ChildActor->bHiddenEd = false;
            ChildActor->SetIsTemporarilyHiddenInEditor(false);

			ChildActor->SetActorHiddenInGame(false); // 如果需要在游戏中也显示，可以添加这一行
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Showed %d child actors in editor."), AttachedActors.Num());
}