#pragma once
extern "C"
{
#include <component/component.h>
}

#include <component/exception.hpp>
#include <component/meta_object.hpp>

#include <cstdarg>
#include <string>

#include <typeinfo>
#include <type_traits>

namespace synapse::component {

	template 
		<typename ObjectType,
			typename =
				typename std::enable_if_t
								<std::is_constructible_v
										<ObjectType, meta_object&>>>
	class prototype
	{
		template <typename... T>
			friend class component;
	public:
		using name_type
					= const char*;
		using object_type
					= ObjectType;
		using native_handle_type
					= synapse_component_interface;

	public:
		prototype
			(const char* pName, meta_object& pMetaobject)
				: __M_prototype_metaobj
						(pMetaobject)
		{
			synapse_component_metadata
				hnd_metadata;

			hnd_metadata
				.component_meta_object
					= pMetaobject.__M_metaobj_handle;
			hnd_metadata
				.component_name
					= pName;
			hnd_metadata
				.component_name_length
					= std::strlen(pName);

			synapse_component_traits
				hnd_traits;

			hnd_traits.initialize
				= [](va_list pVargs)
						{ return 
								reinterpret_cast<void*>
									(new object_type
											(*va_arg(pVargs, meta_object*)); };
			hnd_traits.cleanup
				= [](void* pObject)
						{ delete reinterpret_cast<object_type*>(pObject); };

			synapse_export_interface
				(hnd_metadata, hnd_traits);
		}

	private:
		native_handle_type
			__M_prototype_handle;
		meta_object&
			__M_prototype_metaobj;
	};
}