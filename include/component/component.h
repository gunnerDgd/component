#pragma once
#include <component/defines/export/export.h>
#include <component/interface/component.h>

synapse_component_dll
	synapse_component_interface
		synapse_register_interface
			(const char*);

synapse_component_dll
	void
		synapse_register_interface_attribute
			(synapse_component_interface, const char*, void*, void*);

synapse_component_dll
	synapse_component_interface
		synapse_retrieve_interface
			(const char*);

synapse_component_dll
	synapse_component
		synapse_create_component
			(synapse_component_interface, const char*, void*);

synapse_component_dll
	void
		synapse_delete_component
			(synapse_component);

synapse_component_dll
	synapse_component
		synapse_retrieve_component
			(const char*);

synapse_component_dll
	void*
		synapse_retrieve_component_entity
			(synapse_component);

synapse_component_dll
	synapse_component_interface_attribute
		synapse_retrieve_component_attribute
			(synapse_component, const char*);

synapse_component_dll
	void*
		synapse_retrieve_component_attribute_data
			(synapse_component_interface_attribute);

synapse_component_dll
	void*
		synapse_retrieve_component_attribute_additional
			(synapse_component_interface_attribute);

synapse_component_dll
	uint64_t
		synapse_reference_component
			(synapse_component);

synapse_component_dll
	uint64_t
		synapse_dereference_component
			(synapse_component);