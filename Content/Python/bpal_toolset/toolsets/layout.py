# Copyright (c) 2026 Alex Coulombe. Licensed under the MIT License.

import unreal

import toolset_registry


@unreal.uclass()
class BlueprintLayoutTools(unreal.ToolsetDefinition):
    """Auto-layout Blueprint graphs (Blueprint Anti-Pasta): readable left-to-right flow, straight exec wires."""

    @toolset_registry.tool_call
    @staticmethod
    def layout_graph(blueprint: unreal.Blueprint, graph_name: str) -> bool:
        """Lays out one graph of a Blueprint, with the editor-preference settings of Auto Layout Graph.

        Args:
            blueprint: The Blueprint (or Widget/Animation Blueprint) that owns the graph.
            graph_name: Graph name as list_graphs returns it, e.g. 'EventGraph' or a function name.
        Returns:
            False when the Blueprint has no non-empty graph with that name.
        """
        return unreal.BPALLayoutLibrary.layout_blueprint_graph(blueprint, graph_name)

    @toolset_registry.tool_call
    @staticmethod
    def layout_blueprint(blueprint: unreal.Blueprint) -> int:
        """Lays out every non-empty graph of a Blueprint (event graph pages, functions, macros, collapsed graphs).

        Args:
            blueprint: The Blueprint to lay out.
        Returns:
            How many graphs were laid out.
        """
        return unreal.BPALLayoutLibrary.layout_blueprint(blueprint)

    @toolset_registry.tool_call
    @staticmethod
    def list_graphs(blueprint: unreal.Blueprint) -> list[str]:
        """Lists the names of a Blueprint's non-empty graphs.

        Args:
            blueprint: The Blueprint to inspect.
        Returns:
            Graph names usable with layout_graph.
        """
        return list(unreal.BPALLayoutLibrary.get_blueprint_graph_names(blueprint))
