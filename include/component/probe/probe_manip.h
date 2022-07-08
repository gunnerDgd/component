#pragma once
#include <component/probe/probe_type.h>
#include <component/interface/component.h>

synapse_component_interface
	synapse_component_probe_retrieve_interface
		(synapse_component_probe, const char*);

synapse_component
	synapse_component_probe_retrieve_component
		(synapse_component_probe, const char*);