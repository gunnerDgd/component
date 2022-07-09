#pragma once
#include <component/meta_object/details/meta_object_type.h>

void
	__synapse_component_meta_object_export
		(__synapse_component_meta_object*, const char*, void*);

void*
	__synapse_component_meta_object_import
		(__synapse_component_meta_object*, const char*);