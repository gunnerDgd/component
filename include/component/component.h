#pragma once
#include <component/defines/export/export.h>
#include <component/interface/component.h>

synapse_component_dll
	void
		synapse_export_interface
			(synapse_component_metadata, synapse_component_traits);

synapse_component_dll
	synapse_component_interface
		synapse_import_interface
			(const char*);

synapse_component_dll
	synapse_component
		synapse_create_component
			(synapse_component_interface, const char*, int, ...);

synapse_component_dll
	void
		synapse_delete_component
			(synapse_component);

synapse_component_dll
	synapse_component
		synapse_retrieve_component
			(const char*);

synapse_component_dll
	uint64_t
		synapse_reference_component
			(synapse_component);

synapse_component_dll
	uint64_t
		synapse_dereference_component
			(synapse_component);

synapse_component_dll
	void*
		synapse_retrieve_object
			(synapse_component);

synapse_component_dll
	synapse_component_metadata_type*
		synapse_retrieve_type
			(synapse_component_interface);