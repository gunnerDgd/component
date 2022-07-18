#pragma once
#include <component/details/component_interface_type.h>

typedef struct
	__synapse_component
{
	synapse_memory_block
		component_alloc_block;
	__synapse_component_interface*
		component_interface;

	const char*
		component_name;
	void*
		component_entity;
} __synapse_component;