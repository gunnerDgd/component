#include <component/probe/probe_manip.h>
#include <component/probe/details/probe_manip.h>

synapse_component_interface
	synapse_component_probe_retrieve_interface
		(synapse_component_probe pProbe, const char* pName)
{
	synapse_component_opaque_handle_init
		(synapse_component_interface, hnd_interface,
			__synapse_component_probe_retrieve_interface
				(synapse_component_opaque_handle_reference(pProbe),
					pName));

	return
		hnd_interface;
}

synapse_component
	synapse_component_probe_retrieve_component
		(synapse_component_probe pProbe, const char* pName)
{
	synapse_component_opaque_handle_init
		(synapse_component, hnd_component,
			__synapse_component_probe_retrieve_interface
				(synapse_component_opaque_handle_reference(pProbe),
					pName));

	return
		hnd_component;
}