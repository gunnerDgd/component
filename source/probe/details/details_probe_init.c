#include <component/probe/details/probe_init.h>

__synapse_component_probe*
	__synapse_component_probe_initialize
		(synapse_memory_mman_traits* pMman,
		 synapse_memory_mman_traits* pMmanComponent, 
		 synapse_memory_mman_traits* pMmanInterface)
{
	synapse_memory_mman_block
		hnd_block
			= pMman->allocate
				(pMman->hnd_mman, NULL, sizeof(__synapse_component_probe));
	__synapse_component_probe*
		ptr_probe
			= pMman->block_pointer
				(hnd_block);

	ptr_probe->prb_mman_alloc_block
		= hnd_block;
	ptr_probe->prb_mman_interface
		= pMmanInterface;
	ptr_probe->prb_mman_component
		= pMmanComponent;

	ptr_probe->prb_component
		= synapse_structure_double_linked_initialize
				(pMmanComponent);
	ptr_probe->prb_component_interface
		= synapse_structure_double_linked_initialize
				(pMmanInterface);

	return
		ptr_probe;
}

void
	__synapse_component_probe_cleanup
		(synapse_memory_mman_traits* pMman, __synapse_component_probe* pProbe)
{
	synapse_structure_double_linked_cleanup
		(pProbe->prb_component);
	synapse_structure_double_linked_cleanup
		(pProbe->prb_component_interface);

	pMman->deallocate
		(pMman->hnd_mman, pProbe->prb_mman_alloc_block);
}