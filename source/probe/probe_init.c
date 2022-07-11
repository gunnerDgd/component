#include <component/probe/probe_init.h>
#include <component/probe/details/probe_init.h>

synapse_component_probe
	synapse_component_probe_initialize
		(synapse_memory_manager* pMmanProbe)
{
	synapse_component_opaque_handle_init
		(synapse_component_probe, hnd_probe,
			__synapse_component_probe_initialize
				(pMmanProbe));

	return
		hnd_probe;
}

void
	synapse_component_probe_cleanup
		(synapse_component_probe pProbe)
{
	__synapse_component_probe_cleanup
		(synapse_component_opaque_handle_reference
				(pProbe));
}