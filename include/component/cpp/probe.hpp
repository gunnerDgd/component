#pragma once
#include <component/cpp/meta_object.hpp>

namespace synapse::component {
	class probe
	{
	public:
		template
			<typename ObjectType>
				static
					void export_to(const char*, meta_object&);
		template 
			<>
				static
					void export_to<void>
								  (const char*, meta_object&);

		template
			<typename StringType>
				static
					meta_object
						import_from(StringType&&);
	};
}

template
	<typename ObjectType>
void 
	synapse::component::probe::export_to
		(const char* pName, meta_object& pMetaObject)
{
	synapse_component_metadata
		hnd_metadata;

	hnd_metadata.component_name
		= pName;
	hnd_metadata.component_type
		= &pMetaObject.__M_metaobj_attribute;
	hnd_metadata.component_type->type_additional
		= typeid(ObjectType).hash_code();

	synapse_component_traits
		hnd_traits;

	hnd_traits.initialize
		= [](va_list pArgument)
				{ return
						reinterpret_cast<void*>
							(new ObjectType(*va_arg(pArgument, meta_object*))); };
	hnd_traits.cleanup
		= [](void* pObject)
				{ delete reinterpret_cast<ObjectType*>(pObject); };

	synapse_export_interface
		(hnd_metadata, hnd_traits);
}

template
	<typename StringType>
synapse::component::meta_object
	synapse::component::probe::import_from
		(StringType&& pString)
{
	return
		meta_object
			(synapse_import_interface
					(pString.c_str()));
}