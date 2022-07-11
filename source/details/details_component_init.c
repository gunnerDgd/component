#include <component/details/component_init.h>
#include <Windows.h>

__synapse_component_interface*
	__synapse_component_interface_initialize
		(synapse_memory_manager*    pMman,
		 synapse_component_metadata pMetadata, 
		 synapse_component_traits	pTraits)
{
	synapse_memory_block
		hnd_block
			= pMman->allocate
					(pMman->hnd_mman, NULL, sizeof(__synapse_component_interface));
	__synapse_component_interface*
		ptr_interface
			= pMman->block_pointer
					(hnd_block);

	ptr_interface->if_alloc_block
		= hnd_block;
	ptr_interface->if_metadata
		= pMetadata;
	ptr_interface->if_traits
		= pTraits;

	return
		ptr_interface;
}

__synapse_component*
	__synapse_component_initialize
		(synapse_memory_manager* pMman, __synapse_component_interface* pInterface, va_list pArgument)
{
	synapse_memory_block
		hnd_block
			= pMman->allocate
					(pMman->hnd_mman, NULL, sizeof(__synapse_component));
	__synapse_component*
		ptr_component
			= pMman->block_pointer
					(hnd_block);

	ptr_component->comp_alloc_block
		= hnd_block;

	ptr_component->comp_interface
		= pInterface;
	ptr_component->comp_interface_object
		= pInterface->if_traits.initialize
				(pArgument);
	
	return
		ptr_component;
}

void
	__synapse_component_interface_cleanup
		(synapse_memory_manager* pMman, __synapse_component_interface* pInterface)
{
	pMman->deallocate
		(pMman->hnd_mman, pInterface->if_alloc_block);
}

void
	__synapse_component_cleanup
		(synapse_memory_manager* pMman, __synapse_component* pComponent)
{
	pMman->deallocate
		(pMman->hnd_mman, pComponent->comp_alloc_block);
}