#include <component/component.h>
#include <synapse/__internal/component/init.h>

#include <component/component_init.h>
#include <component/component_manip.h>

#include <component/probe/probe_init.h>
#include <component/probe/probe_manip.h>

#include <synapse/memory/interface/memory_manager.h>
#include <synapse/memory/memory.h>

#include <stdarg.h>

static synapse_memory_manager
			*__synapse_component_mman_probe;
static synapse_component_probe
			 __synapse_component_probe;

synapse_component_dll
	void
		synapse_component_initialize_system
			()
{
	if(!__synapse_component_mman_probe)
		__synapse_component_mman_probe
			= synapse_system_memory_manager();

	if(!synapse_component_opaque_handle_reference
			(__synapse_component_probe))
				__synapse_component_probe
					= synapse_component_probe_initialize
						  (__synapse_component_mman_probe);
}

synapse_component_dll
	void
		synapse_component_cleanup_system
			()
{
	if(synapse_component_opaque_handle_reference
			(__synapse_component_probe))
				synapse_component_probe_cleanup
					(__synapse_component_probe);

	__synapse_component_mman_probe
		= NULL;
	synapse_component_opaque_handle_reference
		(__synapse_component_probe)
			= NULL;

}

synapse_component_dll
	synapse_component_interface
		synapse_register_interface
			(const char* pName)
{
	return
		synapse_component_interface_initialize
			(__synapse_component_probe, pName);
}

synapse_component_dll
	void
		synapse_register_interface_attribute
			(synapse_component_interface pInterface, 
			 const char*				 pAttributeName, 
			 void*						 pAttributeData, 
			 void*						 pAttributeAdditonal)
{
	synapse_component_add_attribute
		(pInterface, pAttributeName, pAttributeData, pAttributeAdditonal);
}

synapse_component_dll
	synapse_component_interface
		synapse_retrieve_interface
			(const char* pInterfaceName)
{
	return
		synapse_component_probe_retrieve_interface
			(__synapse_component_probe, pInterfaceName);
}

synapse_component_dll
	synapse_component
		synapse_create_component
			(synapse_component_interface pInterface, const char* pName, void* pArgument)
{
	if(!synapse_component_opaque_handle_reference
			(pInterface)) {
		synapse_component_opaque_handle_init
			(synapse_component, hnd_error, 0);

		return
			hnd_error;
	}

	return
		synapse_component_initialize
			(__synapse_component_probe, pInterface, pName, pArgument);
}

synapse_component_dll
	void
		synapse_delete_component
			(synapse_component pComponent)
{
	if(!synapse_component_opaque_handle_reference
			(pComponent))
				return;

	synapse_component_cleanup
		(__synapse_component_probe, pComponent);
}

synapse_component_dll
	synapse_component
		synapse_retrieve_component
			(const char* pComponentName)
{
	return
		synapse_component_probe_retrieve_component
			(__synapse_component_probe, pComponentName);
}

synapse_component_dll
	uint64_t
		synapse_reference_component
			(synapse_component pComponent)
{
	if(!synapse_component_opaque_handle_reference
			(pComponent))
				return -1;
	else
		return
			synapse_component_reference
				(pComponent);
}

synapse_component_dll
	uint64_t
		synapse_dereference_component
			(synapse_component pComponent)
{
	if(!synapse_component_opaque_handle_reference
			(pComponent))
				return -1;
	else
		return
			synapse_component_dereference
				(pComponent);
}

synapse_component_dll
	void*
		synapse_retrieve_component_entity
			(synapse_component pComponent)
{
	if(!synapse_component_opaque_handle_reference
			(pComponent))
				return NULL;
	else
		return
			synapse_component_retrieve_entity
				(pComponent);
}

synapse_component_dll
	synapse_component_interface_attribute
		synapse_retrieve_interface_attribute
			(synapse_component_interface pComponent, const char* pName)
{
	return
		synapse_component_retrieve_attribute
			(pComponent, pName);
}

synapse_component_dll
	void*
		synapse_retrieve_interface_attribute_data
			(synapse_component_interface_attribute pAttribute)
{
	return
		synapse_component_retrieve_attribute_data
			(pAttribute);
}

synapse_component_dll
	void*
		synapse_retrieve_interface_attribute_additional
			(synapse_component_interface_attribute pAttribute)
{
	return
		synapse_component_retrieve_attribute_additional
			(pAttribute);
}