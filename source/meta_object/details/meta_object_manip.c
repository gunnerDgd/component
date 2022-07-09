#include <component/meta_object/details/meta_object_manip.h>
#include <string.h>

void
	__synapse_component_meta_object_export
		(__synapse_component_meta_object* pMeta, const char* pName, void* pAttr)
{
	synapse_memory_mman_block
		hnd_attr
			= pMeta->obj_mman->allocate
					(pMeta->obj_mman->hnd_mman, NULL,
							sizeof(__synapse_component_meta_object_attribute));
	__synapse_component_meta_object_attribute*
		ptr_attr
			= pMeta->obj_mman->block_pointer
					(hnd_attr);

	ptr_attr->attr_name
		= pName;
	ptr_attr->attr_pointer
		= pAttr;

	synapse_structure_double_linked_insert_back
		(pMeta->obj_exported, &ptr_attr, 
				sizeof(__synapse_component_meta_object_attribute*));
}

void*
	__synapse_component_meta_object_import
		(__synapse_component_meta_object* pMeta, const char* pName)
{
	synapse_structure_double_linked_node
		ptr_seek
			= synapse_structure_double_linked_node_begin
					(pMeta->obj_exported);

	for( ; ptr_seek.opaque
		 ; ptr_seek = synapse_structure_double_linked_node_next(ptr_seek))
	{
		__synapse_component_meta_object_attribute*
			ptr_attr
				= *(__synapse_component_meta_object_attribute**)
						synapse_structure_double_linked_node_data
							(ptr_seek);

		if(strcmp
				(ptr_attr->attr_name, pName) == 0)
			return
				ptr_attr->attr_pointer;
	}

	return NULL;
}