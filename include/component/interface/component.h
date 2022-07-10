#pragma once
#include <component/defines/handle/opaque_handle.h>
#include <component/interface/attribute.h>

synapse_component_opaque_handle_declare
	(synapse_component_interface);

synapse_component_opaque_handle_declare
	(synapse_component);

typedef struct 
	synapse_component_metadata
{
	const char*
		component_name;
	synapse_component_metadata_type*
		component_type; // Struct / Class Mapping Information for Component Interface.
} synapse_component_metadata;

typedef struct
	synapse_component_traits
{
	void*
		(*initialize)(va_list);
	void
		(*cleanup)   (void*);
} synapse_component_traits;