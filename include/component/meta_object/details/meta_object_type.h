#pragma once
#include <structure/list/double_linked.h>

typedef struct
	__synapse_component_meta_object_attribute
{
	void*
		attr_pointer;
	const char*
		attr_name;
} __synapse_component_meta_object_attribute;

typedef struct
	__synapse_component_meta_object
{
	synapse_structure_double_linked
		obj_exported;
	synapse_memory_mman_traits*
		obj_mman;
} __synapse_component_meta_object;