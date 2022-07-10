#pragma once
extern "C"
{
#include <component/component.h>
}

#include <tuple>
#include <utility>

#include <cstdarg>
#include <component/attribute.hpp>

namespace synapse::component {
	class meta_object
	{
		template <typename T>
			friend class component;

		class attribute_helper
		{
			friend class meta_object;
			synapse_component_metadata_attribute*
				__hlp_attribute;

			attribute_helper
				(synapse_component_metadata_attribute*
					pAttribute)
						: __hlp_attribute(pAttribute) {}

		public:
			template <typename T>
			operator T()
			{ 
				if(typeid(std::remove_reference_t<T>).hash_code() 
						== (std::uint64_t)__hlp_attribute->attr_additional)
								return *reinterpret_cast<T*>
												(__hlp_attribute->attr_ptr);
				else
					throw
						exception::attribute_type_mismatch {};
			}
		};

		meta_object
			(synapse_component_interface);
	public:
		using native_handle_type
				= synapse_component_interface;
		using native_attribute_type
				= synapse_component_metadata_type;
		using name_type
				= const char*;
	
	public:
		template
			<typename... Attribute>
				meta_object
					(Attribute&&... pAttribute)
		{
			static attribute_set
						<std::remove_reference_t<Attribute>...>
							hnd_attribute
								(pAttribute...);

			__M_metaobj_attribute.type_attribute
					= hnd_attribute.attributes;
			__M_metaobj_attribute.type_attribute_count
					= sizeof...(Attribute);
		}

	public:
		attribute_helper
			operator[](std::string);

	public:
		template <typename ObjectType>
		static void
			export_to  (name_type, meta_object&);
		static meta_object
			import_from(name_type);

	private:
		native_attribute_type
			__M_metaobj_attribute;
		native_handle_type
			__M_metaobj_handle;
	};
}

template
	<typename ObjectType>
void 
	synapse::component::meta_object::export_to  
			(name_type pName, meta_object& pMetaObject)
{
	synapse_component_metadata
		hnd_metadata;

	hnd_metadata.component_name
		= pName;
	hnd_metadata.component_type
		= &pMetaObject.__M_metaobj_attribute;

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