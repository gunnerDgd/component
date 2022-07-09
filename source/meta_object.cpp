#include <component/meta_object.hpp>

synapse::component::meta_object::meta_object()
	: __M_metaobj_handle
			(synapse_create_meta_object())
{
	
}

synapse::component::meta_object::meta_object
	(synapse_component_meta_object pMetaObject)
		: __M_metaobj_handle
				(pMetaObject)
{

}

synapse::component::meta_object::~meta_object()
{
	synapse_delete_meta_object
		(__M_metaobj_handle);
}

synapse::component::attribute&
	synapse::component::meta_object::operator[]
		(std::string pName)
{
	attribute*
		ptr_attribute
			= reinterpret_cast<attribute*>
					(synapse_import_attribute_from_meta_object
							(__M_metaobj_handle, pName.c_str()));

	if (!ptr_attribute)
		throw exception::attribute_not_found {};
	return
		*ptr_attribute;
}