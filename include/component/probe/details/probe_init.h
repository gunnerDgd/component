#pragma once
#include <component/probe/details/probe_type.h>

__synapse_component_probe*
	__synapse_component_probe_initialize
		(synapse_memory_mman_traits*, synapse_memory_mman_traits*, synapse_memory_mman_traits*);

void
	__synapse_component_probe_cleanup
		(synapse_memory_mman_traits*, __synapse_component_probe*);