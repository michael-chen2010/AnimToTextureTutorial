// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"


void UMyBlueprintFunctionLibrary::HideChildActorsInEditor(const AActor* ParentActor)
{
    // ��ȡ���и��ӵ���Actor
    TArray<AActor*> AttachedActors;
    ParentActor->GetAttachedActors(AttachedActors);

    // ����������Actor����������
    for (AActor* ChildActor : AttachedActors)
    {
        if (ChildActor)
        {
            ChildActor->SetHidden(true);
            ChildActor->bHiddenEd = true;
            ChildActor->SetIsTemporarilyHiddenInEditor(true);

			ChildActor->SetActorHiddenInGame(true); // �����Ҫ����Ϸ��Ҳ���أ����������һ��
        }
    }

    // ��ӡ��־��ȷ�ϲ���
    UE_LOG(LogTemp, Warning, TEXT("Hid %d child actors in editor."), AttachedActors.Num());
}

void UMyBlueprintFunctionLibrary::ShowChildActorsInEditor(const AActor* ParentActor)
{
    // ��ȡ���и��ӵ���Actor
    TArray<AActor*> AttachedActors;
    ParentActor->GetAttachedActors(AttachedActors);

    // ����������Actor����ʾ����
    for (AActor* ChildActor : AttachedActors)
    {
        if (ChildActor)
        {
            ChildActor->SetHidden(false);
            ChildActor->bHiddenEd = false;
            ChildActor->SetIsTemporarilyHiddenInEditor(false);

			ChildActor->SetActorHiddenInGame(false); // �����Ҫ����Ϸ��Ҳ��ʾ�����������һ��
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Showed %d child actors in editor."), AttachedActors.Num());
}