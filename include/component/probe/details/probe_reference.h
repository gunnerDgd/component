#pragma once
#include <component/probe/details/probe_type.h>

uint64_t
	__synapse_component_probe_reference_interface
		(__synapse_component_probe_interface*);

uint64_t
	__synapse_component_probe_dereference_interface
		(__synapse_component_probe_interface*);

uint64_t
	__synapse_component_probe_reference_component
		(__synapse_component_probe_component*);

uint64_t
	__synapse_component_probe_dereference_component
		(__synapse_component_probe_component*);