#include <component/component.h>
#include <synapse/__internal/component/init.h>

#include <component/component_init.h>
#include <component/component_manip.h>

#include <component/probe/probe_init.h>
#include <component/probe/probe_manip.h>

#include <synapse/memory/interface/memory_manager.h>
#include <synapse/memory/standard_heap.h>

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
			= synapse_initialize_standard_heap();

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

	if(__synapse_component_mman_probe)
		synapse_cleanup_standard_heap
			(__synapse_component_mman_probe);

	__synapse_component_mman_probe
		= NULL;
	synapse_component_opaque_handle_reference
		(__synapse_component_probe)
			= NULL;

}

synapse_component_dll
	void
		synapse_export_interface
			(synapse_component_metadata pMetadata, synapse_component_traits pTraits)
{
	synapse_component_interface_initialize
		(__synapse_component_probe,
				pMetadata, pTraits);
}

synapse_component_dll
	synapse_component_interface
		synapse_import_interface
			(const char* pInterfaceName)
{
	return
		synapse_component_probe_retrieve_interface
			(__synapse_component_probe, pInterfaceName);
}

synapse_component_dll
	synapse_component
		synapse_create_component
			(synapse_component_interface pInterface, const char* pName, int pArgCount, ...)
{
	va_list ptr_args;
	if(!synapse_component_opaque_handle_reference
			(pInterface)) {
		synapse_component_opaque_handle_init
			(synapse_component, hnd_error, 0);

		return
			hnd_error;
	}

	va_start
		(ptr_args, pArgCount);

	return
		synapse_component_initialize_from_vargs
			(__synapse_component_probe, pInterface, pName, ptr_args);
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
		synapse_retrieve_object
			(synapse_component pComponent)
{
	if(!synapse_component_opaque_handle_reference
			(pComponent))
				return NULL;
	else
		return
			synapse_component_retrieve_object
				(pComponent);
}

synapse_component_dll
	synapse_component_metadata_type*
		synapse_retrieve_type
			(synapse_component_interface pInterface)
{
	if(!synapse_component_opaque_handle_reference
			(pInterface))
				return NULL;
	else
		return
			synapse_component_retrieve_type
				(pInterface);
}