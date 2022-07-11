#pragma once
#include <component/probe/probe_type.h>
#include <synapse/memory/interface/memory_manager.h>

synapse_component_probe
	synapse_component_probe_initialize
		(synapse_memory_manager*);

void
	synapse_component_probe_cleanup
		(synapse_component_probe);