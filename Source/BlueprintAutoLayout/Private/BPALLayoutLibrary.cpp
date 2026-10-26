// Copyright (c) 2026 Alex Coulombe. Licensed under the MIT License.

#include "BPALLayoutLibrary.h"
#include "BlueprintAutoLayoutModule.h"

#include "Engine/Blueprint.h"
#include "EdGraph/EdGraph.h"
#include "Kismet2/BlueprintEditorUtils.h"

static TArray<UEdGraph*> GetLayoutGraphs(UBlueprint* Blueprint)
{
	TArray<UEdGraph*> Graphs;
	if (Blueprint)
	{
		Blueprint->GetAllGraphs(Graphs);   // ubergraph pages, functions, macros and their collapsed subgraphs
	}
	Graphs.RemoveAll([](const UEdGraph* Graph) { return Graph == nullptr || Graph->Nodes.Num() == 0; });
	return Graphs;
}

bool UBPALLayoutLibrary::LayoutBlueprintGraph(UBlueprint* Blueprint, const FString& GraphName)
{
	for (UEdGraph* Graph : GetLayoutGraphs(Blueprint))
	{
		if (Graph->GetName() == GraphName)
		{
			FBlueprintAutoLayoutModule::ExecuteLayoutOnGraph(Graph);
			FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
			return true;
		}
	}
	return false;
}

int32 UBPALLayoutLibrary::LayoutBlueprint(UBlueprint* Blueprint)
{
	const TArray<UEdGraph*> Graphs = GetLayoutGraphs(Blueprint);
	for (UEdGraph* Graph : Graphs)
	{
		FBlueprintAutoLayoutModule::ExecuteLayoutOnGraph(Graph);
	}
	if (Graphs.Num() > 0)
	{
		FBlueprintEditorUtils::MarkBlueprintAsModified(Blueprint);
	}
	return Graphs.Num();
}

TArray<FString> UBPALLayoutLibrary::GetBlueprintGraphNames(UBlueprint* Blueprint)
{
	TArray<FString> Names;
	for (const UEdGraph* Graph : GetLayoutGraphs(Blueprint))
	{
		Names.Add(Graph->GetName());
	}
	return Names;
}
