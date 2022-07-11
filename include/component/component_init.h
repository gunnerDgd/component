#pragma once
#include <component/interface/component.h>
#include <component/probe/probe_type.h>


synapse_component_interface
	synapse_component_interface_initialize
		(synapse_component_probe, synapse_component_metadata, synapse_component_traits);

synapse_component
	synapse_component_initialize
		(synapse_component_probe, synapse_component_interface, const char*, int, ...);

synapse_component
	synapse_component_initialize_from_vargs
		(synapse_component_probe, synapse_component_interface, const char*, va_list);

void
	synapse_component_interface_cleanup
		(synapse_component_probe, synapse_component_interface);

void
	synapse_component_cleanup
		(synapse_component_probe, synapse_component);