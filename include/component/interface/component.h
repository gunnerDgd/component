#pragma once
#include <component/defines/handle/opaque_handle.h>

synapse_component_opaque_handle_declare
	(synapse_component_interface);

synapse_component_opaque_handle_declare
	(synapse_component);

synapse_component_opaque_handle_declare
	(synapse_component_meta_object);

typedef struct 
	synapse_component_metadata
{
	char*
		component_name;
	size_t
		component_name_length;
	synapse_component_meta_object
		component_meta_object; // Struct / Class Mapping Information for Component Interface.
} synapse_component_metadata;

typedef struct
	synapse_component_traits
{
	void*
		(*initialize)(va_list);
	void
		(*cleanup)   (void*);
} synapse_component_traits;