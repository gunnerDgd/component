#include <component/probe/details/probe_init.h>

__synapse_component_probe*
	__synapse_component_probe_initialize
		(synapse_memory_manager* pMmanProbe)
{
	synapse_memory_block
		hnd_block
			= pMmanProbe->allocate
				(pMmanProbe->hnd_mman, NULL, sizeof(__synapse_component_probe));
	__synapse_component_probe*
		ptr_probe
			= pMmanProbe->block_pointer
				(hnd_block);

	ptr_probe->prb_mman_alloc_block
		= hnd_block;
	ptr_probe->prb_mman_probe
		= pMmanProbe;

	ptr_probe->prb_component
		= synapse_structure_double_linked_initialize
				(pMmanProbe);
	ptr_probe->prb_component_interface
		= synapse_structure_double_linked_initialize
				(pMmanProbe);

	return
		ptr_probe;
}

void
	__synapse_component_probe_cleanup
		(__synapse_component_probe* pProbe)
{
	synapse_structure_double_linked_cleanup
		(pProbe->prb_component);
	synapse_structure_double_linked_cleanup
		(pProbe->prb_component_interface);

	pProbe->prb_mman_probe->deallocate
		(pProbe->prb_mman_probe->hnd_mman,
			pProbe->prb_mman_alloc_block);
}