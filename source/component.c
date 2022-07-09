#include <component/component.h>

#include <component/component_init.h>
#include <component/component_manip.h>

#include <component/probe/probe_init.h>
#include <component/probe/probe_manip.h>
#include <component/meta_object/meta_object.h>

#include <memory/mman/standard_heap/stdheap.h>

#include <stdarg.h>

static synapse_memory_mman_traits
			*__synapse_component_mman_global,
			*__synapse_component_mman_interface,
			*__synapse_component_mman_component;

static synapse_component_probe
			 __synapse_component_probe;

synapse_component_dll
	void
		synapse_component_initialize_system
			()
{
	__synapse_component_mman_global
		= synapse_memory_mman_stdheap_initialize_traits();
	__synapse_component_mman_interface
		= synapse_memory_mman_stdheap_initialize_traits();
	__synapse_component_mman_component
		= synapse_memory_mman_stdheap_initialize_traits();

	__synapse_component_probe
		= synapse_component_probe_initialize
				(__synapse_component_mman_global,
				 __synapse_component_mman_component,
				 __synapse_component_mman_global);
}

synapse_component_dll
	void
		synapse_component_cleanup_system
			()
{
	synapse_component_probe_cleanup
		(__synapse_component_mman_global, __synapse_component_probe);
	
	synapse_memory_mman_stdheap_cleanup_traits
		(__synapse_component_mman_component);
	synapse_memory_mman_stdheap_cleanup_traits
		(__synapse_component_mman_interface);
	synapse_memory_mman_stdheap_cleanup_traits
		(__synapse_component_mman_global);
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
	void*
		synapse_component_object
			(synapse_component pComponent)
{
	return
		synapse_component_retrieve_object
			(pComponent);
}

synapse_component_dll
	synapse_component_meta_object
		synapse_meta_object_from_component
			(synapse_component pComponent)
{
	return
		synapse_component_retrieve_meta_object
			(pComponent);
}

synapse_component_dll
	synapse_component_meta_object
		synapse_create_meta_object
			()
{
	return
		synapse_component_meta_object_initialize
			();
}

synapse_component_dll
	void
		synapse_delete_meta_object
			(synapse_component_meta_object pMeta)
{
	synapse_component_meta_object_cleanup
		(pMeta);
}

synapse_component_dll
	void
		synapse_export_attribute_to_meta_object
			(synapse_component_meta_object pMeta, const char* pName, void* pAttr)
{
	synapse_component_meta_export_attribute
		(pMeta, pName, pAttr);
}

synapse_component_dll
	void*
		synapse_import_attribute_from_meta_object
			(synapse_component_meta_object pMeta, const char* pName)
{
	return
		synapse_component_meta_import_attribute
			(pMeta, pName);
}