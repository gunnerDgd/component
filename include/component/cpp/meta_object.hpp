#pragma once
extern "C"
{
#include <component/component.h>
}

#include <cstdarg>
#include <component/cpp/attribute.hpp>

namespace synapse::component {
	class meta_object
	{
		template <typename T>
			friend class component;
			friend class probe;

		class attribute_helper
		{
			friend class meta_object;
			synapse_component_metadata_attribute*
				__hlp_attribute;

			attribute_helper
				(synapse_component_metadata_attribute*);

		public:
			template <typename T>
				 operator T();
			template <typename T>
			bool operator==(T&&);
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
					(Attribute&&... pAttribute);

	public:
		attribute_helper
			operator[](std::string);

	private:
		native_attribute_type
			__M_metaobj_attribute;
		native_handle_type
			__M_metaobj_handle;
	};
}

template
	<typename... Attribute>
		synapse::component::meta_object::meta_object
			(Attribute&&... pAttribute)
{
	attribute_set
		<std::remove_reference_t<Attribute>...>*
			hnd_attribute
				= new attribute_set
						<std::remove_reference_t<Attribute>...>
							(pAttribute...);

	__M_metaobj_attribute.type_attribute
		= hnd_attribute->attributes;
	__M_metaobj_attribute.type_attribute_count
		= sizeof...(Attribute);
}

template <typename T>
	synapse::component::meta_object::attribute_helper::operator T()
{
	if (typeid(std::remove_reference_t<T>).hash_code()
			== (std::uint64_t)__hlp_attribute->attr_additional)
				return *reinterpret_cast<T*>
							(__hlp_attribute->attr_ptr);
	else
		throw
			exception::attribute_type_mismatch{};
}

template <typename T>
bool 
	synapse::component::meta_object::attribute_helper::operator==
		(T&&)
{
	return
		(typeid(std::remove_reference_t<T>).hash_code()
			== (std::uint64_t)__hlp_attribute->attr_additional);
}