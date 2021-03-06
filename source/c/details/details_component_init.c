#include <component/details/component_init.h>
#include <component/details/component_manip.h>

#include <synapse/memory/memory.h>

#include <Windows.h>

__synapse_component_interface*
	__synapse_component_interface_initialize
		(synapse_memory_manager* pMman,
		 const char*			 pInterfaceName)
{
	__synapse_component_interface*
		ptr_interface
			= synapse_system_allocate
					(sizeof(__synapse_component_interface));

	ptr_interface->if_name
		= pInterfaceName;
	ptr_interface->if_attribute
		= synapse_initialize_double_linked
			(pMman);

	return
		ptr_interface;
}

__synapse_component*
	__synapse_component_initialize
		(synapse_memory_manager* 		pMman, 
		 const char*					pComponentName,
		 __synapse_component_interface* pInterface, 
		 void*	 						pArgument)
{
	synapse_memory_block
		hnd_block;
	__synapse_component*
		ptr_component;
	__synapse_component_interface_attribute*
		ptr_initializer
			= __synapse_component_interface_retreive_attribute
					(pInterface, "initialize");
	
	if(!ptr_initializer)
		return NULL;

	hnd_block
		= pMman->allocate
				(pMman->hnd_mman, NULL, sizeof(__synapse_component));
	ptr_component
		= pMman->block_pointer
				(hnd_block);

	ptr_component->component_alloc_block
		= hnd_block;
	ptr_component->component_interface
		= pInterface;
	ptr_component->component_name
		= pComponentName;

	ptr_component->component_entity
		= ptr_initializer->attr_function_ptr
				(pArgument);

	return
		ptr_component;
}

void
	__synapse_component_interface_cleanup
		(synapse_memory_manager* pMman, __synapse_component_interface* pInterface)
{	
	synapse_cleanup_double_linked
		(pInterface->if_attribute);
	synapse_system_deallocate
		(pInterface);
}

void
	__synapse_component_cleanup
		(synapse_memory_manager* pMman, __synapse_component* pComponent)
{
	__synapse_component_interface_attribute*
		ptr_attribute
			= __synapse_component_interface_retreive_attribute
					(pComponent->component_interface, "cleanup");

	if(ptr_attribute)
		ptr_attribute->attr_function_ptr
			(pComponent->component_entity);

	pMman->deallocate
		(pMman->hnd_mman, pComponent->component_alloc_block);
}