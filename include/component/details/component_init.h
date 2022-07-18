#pragma once
#include <component/details/component_type.h>

__synapse_component_interface*
	__synapse_component_interface_initialize
		(synapse_memory_manager*, const char*);

__synapse_component*
	__synapse_component_initialize
		(synapse_memory_manager*, const char*, __synapse_component_interface*, void*);

void
	__synapse_component_interface_cleanup
		(synapse_memory_manager*, __synapse_component_interface*);

void
	__synapse_component_cleanup
		(synapse_memory_manager*, __synapse_component*);