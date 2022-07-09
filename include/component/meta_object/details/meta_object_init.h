#pragma once
#include <component/meta_object/details/meta_object_type.h>

__synapse_component_meta_object*
	__synapse_component_meta_object_initialize
		(synapse_memory_mman_traits*);

void
	__synapse_component_meta_object_cleanup
		(__synapse_component_meta_object*);