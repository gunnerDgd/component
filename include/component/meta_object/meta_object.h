#pragma once
#include <component/interface/component.h>
#include <memory/mman/mman_traits.h>

synapse_component_meta_object
	synapse_component_meta_object_initialize
		();

void
	synapse_component_meta_object_cleanup
		(synapse_component_meta_object);

void
	synapse_component_meta_export_attribute
		(synapse_component_meta_object, const char*, void*);

void*
	synapse_component_meta_import_attribute
		(synapse_component_meta_object, const char*);