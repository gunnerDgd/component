#pragma once
#include <component/interface/component.h>

uint64_t
	synapse_component_reference
		(synapse_component);

uint64_t
	synapse_component_dereference
		(synapse_component);

void*
	synapse_component_retrieve_entity
		(synapse_component);

synapse_component_interface_attribute
	synapse_component_retrieve_attribute
		(synapse_component, const char*);

void*
	synapse_component_retrieve_attribute_data
		(synapse_component_interface_attribute);

void*
	synapse_component_retrieve_attribute_additional
		(synapse_component_interface_attribute);