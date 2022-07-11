#pragma once
#include <component/probe/details/probe_type.h>

__synapse_component_probe*
	__synapse_component_probe_initialize
		(synapse_memory_manager*);

void
	__synapse_component_probe_cleanup
		(__synapse_component_probe*);