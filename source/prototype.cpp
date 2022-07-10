#include <component/prototype.hpp>

synapse::component::prototype::prototype
	(const char* pName)
		: __M_prototype_handle
				(synapse_import_interface(pName)),
		  __M_prototype_name
				(nullptr)
{
	if (!synapse_component_opaque_handle_reference
			(__M_prototype_handle))
					throw exception::prototype_not_found{};
}

synapse::component::prototype::prototype
	(const char* pName, meta_object& pMetaobject)
		: __M_prototype_name
				(new char[std::strlen(pName) + 1])
{
	synapse_component_metadata
		hnd_metadata;

	std::memset
			(__M_prototype_name, 0x00, std::strlen(pName) + 1);
	std::strcpy
			(__M_prototype_name, pName);

	hnd_metadata
		.component_meta_object
			= pMetaobject.__M_metaobj_handle;
	hnd_metadata
		.component_name 
			= __M_prototype_name;
	hnd_metadata
		.component_name_length
			= std::strlen(pName);

	synapse_component_traits
		hnd_traits;

	hnd_traits.initialize
			= [](va_list pVargs)->void* { return NULL; };
	hnd_traits.cleanup
			= [](void* pObject) {};

	synapse_export_interface
			(hnd_metadata, hnd_traits);
}

synapse::component::prototype::~prototype()
{
	if(__M_prototype_name)
		delete[] __M_prototype_name;
}