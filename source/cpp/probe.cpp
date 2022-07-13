#include <component/cpp/probe.hpp>

template <>
void 
	synapse::component::probe::export_to<void>
		(const char* pName, meta_object& pMetaObject)
{
	synapse_component_metadata
		hnd_metadata;

	hnd_metadata.component_name
		= pName;
	hnd_metadata.component_type
		= &pMetaObject.__M_metaobj_attribute;
	hnd_metadata.component_type->type_additional
		= 0;

	synapse_component_traits
		hnd_traits;

	hnd_traits.initialize
			= [](va_list pArgument)->void*
					{ return nullptr; };
	hnd_traits.cleanup
			= [](void* pObject) {  };

	synapse_export_interface
		(hnd_metadata, hnd_traits);
}
