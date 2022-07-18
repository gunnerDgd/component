#pragma once
#include <component/probe/details/probe_type.h>

__synapse_component_probe_interface*
	__synapse_component_probe_register_interface
		(__synapse_component_probe*, const char*);

void
	__synapse_component_probe_unregister_interface
		(__synapse_component_probe*, __synapse_component_probe_interface*);

__synapse_component_probe_interface*
	__synapse_component_probe_retrieve_interface
		(__synapse_component_probe*, const char*);

void
	__synapse_component_probe_add_attribute
		(__synapse_component_probe_interface*, void*, const char*, void*);

void
	__synapse_component_probe_delete_attribute
		(__synapse_component_probe_interface*, const char*);

__synapse_component_interface_attribute*
	__synapse_component_probe_retrieve_attribute
		(__synapse_component_probe_interface*, const char*);

__synapse_component_probe_component*
	__synapse_component_probe_add_component
		(__synapse_component_probe*, __synapse_component_probe_interface*, const char*, void*);

void
	__synapse_component_probe_delete_component
		(__synapse_component_probe*, __synapse_component_probe_component*);

__synapse_component_probe_component*
	__synapse_component_probe_retrieve_component
		(__synapse_component_probe*, const char*);