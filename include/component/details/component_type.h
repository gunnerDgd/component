#pragma once
#include <component/interface/component.h>
#include <synapse/memory/interface/memory_manager.h>

typedef struct
	__synapse_component_interface
{
	synapse_memory_block
		if_alloc_block;

	synapse_component_metadata
		if_metadata;
	synapse_component_traits
		if_traits;
} __synapse_component_interface;

typedef struct
	__synapse_component
{
	synapse_memory_block
		comp_alloc_block;

	__synapse_component_interface*
		comp_interface;
	const char*
		comp_name;
	size_t
		comp_name_length;

	void*
		comp_interface_object;
} __synapse_component;