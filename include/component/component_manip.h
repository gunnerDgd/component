#pragma once
#include <component/interface/component.h>

uint64_t
	synapse_component_reference
		(synapse_component);

uint64_t
	synapse_component_dereference
		(synapse_component);

void*
	synapse_component_retrieve_object
		(synapse_component);

synapse_component_metadata_type*
	synapse_component_retrieve_type
		(synapse_component_interface);