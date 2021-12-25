// Fill out your copyright notice in the Description page of Project Settings.

#include "AAAction.h"

#include "AAAreaActionsComponent.h"
#include "FGPlayerController.h"

void AAAAction::Run_Implementation() {
}

void AAAAction::Done()
{
	this->AreaActionsComponent->ActionDone();
}

void AAAAction::Cancel()
{
	this->OnCancel();
	this->Done();
}

FText AAAAction::GetActionName(const TSubclassOf<AAAAction> InClass)
{
	if(!InClass) return FText::FromString(TEXT("N/A"));
	return InClass.GetDefaultObject()->Name;
}

FText AAAAction::GetActionDescription(const TSubclassOf<AAAAction> InClass)
{
	if(!InClass) return FText::FromString(TEXT("N/A"));
	return InClass.GetDefaultObject()->Description;
}

TSubclassOf<UAAActionCategory> AAAAction::GetActionCategory(const TSubclassOf<AAAAction> InClass)
{
	if(!InClass) return UAAActionCategory::StaticClass();
	return InClass.GetDefaultObject()->Category;
}

UTexture2D* AAAAction::GetActionIcon(const TSubclassOf<AAAAction> InClass)
{
	if(!InClass) return nullptr;
	return InClass.GetDefaultObject()->Icon;
}

void AAAAction::OnCancel_Implementation()
{
}
