#include <component/meta_object/meta_object.h>
#include <component/meta_object/details/meta_object_init.h>
#include <component/meta_object/details/meta_object_manip.h>

#include <memory/mman/standard_heap/stdheap.h>

synapse_component_meta_object
	synapse_component_meta_object_initialize
		()
{
	synapse_component_opaque_handle_init
		(synapse_component_meta_object, hnd_meta,
			__synapse_component_meta_object_initialize
				(synapse_memory_mman_stdheap_initialize_traits()));

	return
		hnd_meta;
}

void
	synapse_component_meta_object_cleanup
		(synapse_component_meta_object pMeta)
{
	synapse_memory_mman_traits*
		pMman
			= synapse_component_opaque_handle_cast
				(pMeta, __synapse_component_meta_object*)
					->obj_mman;

	__synapse_component_meta_object_cleanup
		(synapse_component_opaque_handle_reference
			(pMeta));
	synapse_memory_mman_stdheap_cleanup_traits
		(pMman);
}

void
	synapse_component_meta_export_attribute
		(synapse_component_meta_object pMeta, const char* pName, void* pAttr)
{
	__synapse_component_meta_object_export
		(synapse_component_opaque_handle_reference
			(pMeta), pName, pAttr);
}

void*
	synapse_component_meta_import_attribute
		(synapse_component_meta_object pMeta, const char* pName)
{
	return
		__synapse_component_meta_object_import
			(synapse_component_opaque_handle_reference
				(pMeta), pName);
}