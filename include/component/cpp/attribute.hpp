#pragma once
#include <string>
#include <type_traits>

#include <typeinfo>
#include <component/cpp/exception.hpp>
#include <component/interface/attribute.h>

namespace synapse::component {

	template
		<typename AttributeType>
	struct __attribute_value_type
	{
		using type
				= std::conditional_t
						<std::is_function_v<AttributeType>,
								std::remove_reference_t<AttributeType>*, 
									std::remove_reference_t<AttributeType>>;
	};

	template <typename AttributeType>
	struct attribute
	{
		using name_type
				= const char*;
		using value_type
				= typename
						__attribute_value_type<AttributeType>::type;
		using native_attribute_type
				= synapse_component_metadata_attribute;

		attribute
			(name_type pName, value_type pValue)
		{
			static value_type
					attr_static = pValue;

			attribute_field.attr_name
					= pName;
			attribute_field.attr_ptr
					= &attr_static;
			attribute_field.attr_additional
					= reinterpret_cast<void*>
							(typeid(value_type).hash_code());
		}

		native_attribute_type
				attribute_field;
	};

	template
		<std::size_t Idx, typename Attribute, typename... Remaining>
	void
		__initialize_attribute
			(synapse_component_metadata_attribute* pAttr, 
				Attribute& pAttribute, Remaining&... pRemaining)
	{
		pAttr[Idx]
			= pAttribute.attribute_field;

		__initialize_attribute
				<Idx + 1>(pAttr, pRemaining...);
	}

	template
		<std::size_t Idx, typename Attribute>
	void
		__initialize_attribute
				(synapse_component_metadata_attribute* pAttr,
						Attribute& pAttribute)
	{
		pAttr[Idx]
				= pAttribute.attribute_field;
	}

	template
		<typename... Attributes>
	struct attribute_set
	{
		synapse_component_metadata_attribute
				attributes[sizeof...(Attributes)];

		attribute_set
				(Attributes&... pAttributes)
		{
			__initialize_attribute
					<0>(attributes, pAttributes...);
		}
	};
}