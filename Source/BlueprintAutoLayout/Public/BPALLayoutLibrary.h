// Copyright (c) 2026 Alex Coulombe. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPALLayoutLibrary.generated.h"

class UBlueprint;

/**
 * Scriptable entry points (editor Python, Editor Utility Blueprints, the bundled MCP toolset).
 * Each call is one undo step per graph and uses the same settings as the toolbar's Auto Layout Graph.
 */
UCLASS()
class BLUEPRINTAUTOLAYOUT_API UBPALLayoutLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Lay out one graph (event graph page, function, macro or collapsed graph) by name. Returns false when no graph has that name. */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Anti-Pasta")
	static bool LayoutBlueprintGraph(UBlueprint* Blueprint, const FString& GraphName);

	/** Lay out every graph in the Blueprint. Returns how many graphs were laid out. */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Anti-Pasta")
	static int32 LayoutBlueprint(UBlueprint* Blueprint);

	/** Names of the Blueprint's graphs, as LayoutBlueprintGraph expects them. */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Anti-Pasta")
	static TArray<FString> GetBlueprintGraphNames(UBlueprint* Blueprint);
};
