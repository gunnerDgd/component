#pragma once
extern "C"
{
#include <component/component.h>
}

#include <component/attribute.hpp>

namespace synapse::component {
	class meta_object
	{
		template <typename... T>
			friend class prototype;
		template <typename... T>
			friend class component;

		meta_object
			(synapse_component_meta_object);
	public:
		using name_type
					= std::string;
		using native_handle_type
					= synapse_component_meta_object;
	
	public:
		meta_object ();
		~meta_object();
	public:
		template <typename Attribute>
		std::enable_if_t
			<std::is_same_v
				<std::remove_all_extents_t<Attribute>,
					attribute>, meta_object&>
						operator|(Attribute&& pAttribute)
		{
			static attribute
					hnd_attribute(pAttribute);

			synapse_export_attribute_to_meta_object
				(__M_metaobj_handle,
					hnd_attribute.__M_attr_name, &hnd_attribute);
		}

		attribute& 
			operator[](std::string);

	private:
		native_handle_type
			__M_metaobj_handle;
	};
}