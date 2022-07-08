#pragma once
#include <component/probe/details/probe_type.h>

__synapse_component_probe_interface*
	__synapse_component_probe_register_interface
		(__synapse_component_probe*, synapse_component_metadata, synapse_component_traits);

void
	__synapse_component_probe_unregister_interface
		(__synapse_component_probe*, __synapse_component_probe_interface*);

__synapse_component_probe_component*
	__synapse_component_probe_create_component
		(__synapse_component_probe*, __synapse_component_probe_interface*, const char*, va_list);

void
	__synapse_component_probe_delete_component
		(__synapse_component_probe*, __synapse_component_probe_component*);


__synapse_component_probe_interface*
	__synapse_component_probe_retrieve_interface
		(__synapse_component_probe*, const char*);

__synapse_component_probe_component*
	__synapse_component_probe_retrieve_component
		(__synapse_component_probe*, const char*);