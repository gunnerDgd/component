#pragma once
#include <component/details/component_type.h>

__synapse_component_interface*
	__synapse_component_interface_initialize
		(synapse_memory_mman_traits*, synapse_component_metadata, synapse_component_traits);

__synapse_component*
	__synapse_component_initialize
		(synapse_memory_mman_traits*, __synapse_component_interface*, va_list);

void
	__synapse_component_interface_cleanup
		(synapse_memory_mman_traits*, __synapse_component_interface*);

void
	__synapse_component_cleanup
		(synapse_memory_mman_traits*, __synapse_component*);