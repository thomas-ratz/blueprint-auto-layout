# Copyright (c) 2026 Alex Coulombe. Licensed under the MIT License.
# Registers the MCP toolset when the ToolsetRegistry plugin is enabled; the plugin works without it.

try:
    from bpal_toolset import toolsets
except ImportError:
    toolsets = None

if toolsets is not None:
    toolsets._registration.register()
