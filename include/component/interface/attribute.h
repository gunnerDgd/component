#pragma once
#include <component/defines/handle/opaque_handle.h>

typedef struct
	synapse_component_metadata_attribute
{
	void*
		attr_ptr;
	const char*
		attr_name;
	void*
		attr_additional;
} synapse_component_metadata_attribute;

typedef struct
	synapse_component_metadata_type
{
	uint16_t
		  type_attribute_count;
	synapse_component_metadata_attribute
		* type_attribute;
	void
		* type_additional;
} synapse_component_metadata_type;