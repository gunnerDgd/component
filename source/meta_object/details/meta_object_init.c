#include <component/meta_object/details/meta_object_init.h>

#include <stdlib.h>
#include <memory/defines/alloc.h>

__synapse_component_meta_object*
	__synapse_component_meta_object_initialize
		(synapse_memory_mman_traits* pMmanTraits)
{
	__synapse_component_meta_object*
		ptr_metaobj
			= synapse_memory_default_alloc
					(NULL, sizeof(__synapse_component_meta_object));

	ptr_metaobj->obj_exported
		= synapse_structure_double_linked_initialize
				(pMmanTraits);

	return
		ptr_metaobj;
}

void
	__synapse_component_meta_object_cleanup
		(__synapse_component_meta_object* pMetaObject)
{
	pMetaObject->obj_mman->deallocate_all
		(pMetaObject->obj_mman->hnd_mman);

	synapse_memory_default_dealloc
		(pMetaObject, sizeof(__synapse_component_meta_object));
}