#include <component/meta_object.hpp>

synapse::component::meta_object::meta_object
	(synapse_component_interface pInterface)
		: __M_metaobj_handle
				(pInterface)
{
	if(!synapse_component_opaque_handle_reference
			(__M_metaobj_handle))
				throw exception::interface_not_found {};

	__M_metaobj_attribute
			= *synapse_retrieve_type
						(__M_metaobj_handle);
}

synapse::component::meta_object
	synapse::component::meta_object::import_from
		(name_type pName)
{
	return
		meta_object
			(synapse_import_interface(pName));
}

synapse::component::meta_object::attribute_helper
	synapse::component::meta_object::operator[]
		(std::string pName)
{
	for(uint16_t i = 0 ;
				 i < __M_metaobj_attribute.type_attribute_count;
				 i++)
		if(pName
				== __M_metaobj_attribute.type_attribute[i].attr_name)
					return 
						attribute_helper
								(&__M_metaobj_attribute.type_attribute[i]);

	throw
		exception::attribute_not_found {};
}