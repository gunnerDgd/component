#include <component/probe/details/probe_manip.h>
#include <component/probe/details/probe_reference.h>

#include <component/details/component_init.h>
#include <component/details/component_manip.h>

#include <string.h>

__synapse_component_probe_interface*
	__synapse_component_probe_register_interface
		(__synapse_component_probe* pProbe, 
		 const char*				pInterfaceName)
{
	synapse_memory_block
		hnd_interface_mblock;
	__synapse_component_probe_interface*
		ptr_interface;

	if(__synapse_component_probe_retrieve_interface
			(pProbe, pInterfaceName)) 
				return NULL;
	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return NULL;

	hnd_interface_mblock
		= pProbe->prb_mman_probe->allocate
				(pProbe->prb_mman_probe->hnd_mman,
					NULL, sizeof(__synapse_component_probe_interface));

	ptr_interface
		= pProbe->prb_mman_probe->block_pointer
			(hnd_interface_mblock);
	
	ptr_interface->prb_interface_mblock
		= hnd_interface_mblock;

	ptr_interface->prb_interface
		= __synapse_component_interface_initialize
				(pProbe->prb_mman_probe, pInterfaceName);
	ptr_interface->prb_interface_handle
		= synapse_structure_double_linked_insert_back
				(pProbe->prb_component_interface,
					&ptr_interface, sizeof(__synapse_component_probe_interface*));

	return
		ptr_interface;
}

__synapse_component_probe_component*
	__synapse_component_probe_create_component
		(__synapse_component_probe*			  pProbe			 , 
		 __synapse_component_probe_interface* pComponentInterface,
		 const char*						  pComponentName     ,
		 void*								  pArgument)
{
	synapse_memory_block
		hnd_component_mblock;
	__synapse_component_probe_component*
		ptr_component;

	if(__synapse_component_probe_retrieve_component
			(pProbe, pComponentName))
				return NULL;
	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return NULL;

	hnd_component_mblock
		= pProbe->prb_mman_probe->allocate
			(pProbe->prb_mman_probe->hnd_mman,
				NULL, sizeof(__synapse_component_probe_component));

	ptr_component
		= pProbe->prb_mman_probe->block_pointer
			(hnd_component_mblock);

	ptr_component->prb_component_mblock
		= hnd_component_mblock;
	ptr_component->prb_component
		= __synapse_component_initialize
			(pProbe->prb_mman_probe, pComponentName,
				pComponentInterface->prb_interface, pArgument);

	ptr_component->prb_component_node
		= synapse_structure_double_linked_insert_back
				(pProbe->prb_component, &ptr_component, sizeof(__synapse_component_probe_component*));
	ptr_component->prb_component_refcount
		= 1;

	__synapse_component_probe_reference_interface
		(pComponentInterface);

	return
		ptr_component;
}

void
	__synapse_component_probe_unregister_interface
		(__synapse_component_probe*			  pProbe, 
		 __synapse_component_probe_interface* pProbeInterface)
{
	if (pProbeInterface->prb_interface_refcount)
		return;
	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return;

	__synapse_component_interface_cleanup
		(pProbe->prb_mman_probe,
			pProbeInterface->prb_interface);
	
	pProbe->prb_mman_probe->deallocate
		(pProbe->prb_mman_probe->hnd_mman,
			pProbeInterface->prb_interface_mblock);
}

void
	__synapse_component_probe_delete_component
		(__synapse_component_probe* pProbe, __synapse_component_probe_component* pProbeComponent)
{
	if (pProbeComponent->prb_component_refcount) {
		__synapse_component_probe_dereference_component
			(pProbeComponent);
		return;
	}

	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return NULL;

	synapse_structure_double_linked_erase_at
		(pProbe->prb_component, pProbeComponent->prb_component_node);
	__synapse_component_cleanup
		(pProbe->prb_mman_probe, pProbeComponent->prb_component);
	
	
	pProbe->prb_mman_probe->deallocate
		(pProbe->prb_mman_probe->hnd_mman,
			pProbeComponent->prb_component->component_alloc_block);

	pProbe->prb_mman_probe->deallocate
		(pProbe->prb_mman_probe->hnd_mman,
			pProbeComponent->prb_component_mblock);
}

__synapse_component_probe_interface*
	__synapse_component_probe_retrieve_interface
		(__synapse_component_probe* pProbe, const char* pName)
{
	synapse_structure_double_linked_node
		ptr_seek;

	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return NULL;

	ptr_seek
		= synapse_structure_double_linked_node_begin
				(pProbe->prb_component_interface);

	for( ; ptr_seek.opaque
		 ; ptr_seek = synapse_structure_double_linked_node_next
						(ptr_seek))
	{
		__synapse_component_probe_interface*
			ptr_interface
				= *(__synapse_component_probe_interface**)
						synapse_structure_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_interface->prb_interface->if_name,
						pName) == 0)
			return
				ptr_interface;
	}

	return NULL;
}

__synapse_component_probe_component*
	__synapse_component_probe_retrieve_component
		(__synapse_component_probe* pProbe, const char* pName)
{
	synapse_structure_double_linked_node
		ptr_seek;

	WaitForSingleObject
		(pProbe->prb_thread_lock, INFINITE);

	ptr_seek
		= synapse_structure_double_linked_node_begin
				(pProbe->prb_component);

	for( ; ptr_seek.opaque
		 ; ptr_seek = synapse_structure_double_linked_node_next
						(ptr_seek))
	{
		__synapse_component_probe_component*
			ptr_component
				= *(__synapse_component_probe_component**)
						synapse_structure_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_component->prb_component->component_name,
						pName) == 0) {
			ReleaseMutex
				(pProbe->prb_thread_lock);
			return
				ptr_component;
		}
	}

	ReleaseMutex
		(pProbe->prb_thread_lock);
	return NULL;
}


void
	__synapse_component_probe_add_attribute
		(__synapse_component_probe*			  pProbe    ,
		 __synapse_component_probe_interface* pInterface, 
		 void*								  pAttribute, 
		 const char*						  pAttributeName, 
		 void*								  pAttributeAdditional)
{
	__synapse_component_interface_add_attribute
		(pInterface->prb_interface, 
			pAttributeName, pAttribute, pAttributeAdditional);
}

void
	__synapse_component_probe_delete_attribute
		(__synapse_component_probe_interface* pInterface, const char* pAttributeName)
{
	__synapse_component_interface_delete_attribute
		(pInterface->prb_interface, pAttributeName);
}

__synapse_component_interface_attribute*
	__synapse_component_probe_retrieve_attribute
		(__synapse_component_probe_interface* pInterface, const char* pAttributeName)
{
	return
		__synapse_component_interface_retreive_attribute
			(pInterface->prb_interface, pAttributeName);
}