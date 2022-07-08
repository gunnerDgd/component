#pragma once
#include <component/probe/probe_type.h>
#include <memory/mman/mman_traits.h>

synapse_component_probe
	synapse_component_probe_initialize
		(synapse_memory_mman_traits*, synapse_memory_mman_traits*, synapse_memory_mman_traits*);

void
	synapse_component_probe_cleanup
		(synapse_memory_mman_traits*, synapse_component_probe);