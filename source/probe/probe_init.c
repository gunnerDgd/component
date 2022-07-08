#include <component/probe/probe_init.h>
#include <component/probe/details/probe_init.h>

synapse_component_probe
	synapse_component_probe_initialize
		(synapse_memory_mman_traits* pMman, 
		 synapse_memory_mman_traits* pMmanComponent, 
		 synapse_memory_mman_traits* pMmanInterface)
{
	synapse_component_opaque_handle_init
		(synapse_component_probe, hnd_probe,
			__synapse_component_probe_initialize
				(pMman, pMmanComponent, pMmanInterface));

	return
		hnd_probe;
}

void
	synapse_component_probe_cleanup
		(synapse_memory_mman_traits* pMman, synapse_component_probe pProbe)
{
	__synapse_component_probe_cleanup
		(pMman,
			synapse_component_opaque_handle_reference
				(pProbe));
}