#pragma once
#include <component/attribute.hpp>

namespace synapse::component {
	template
		<typename ExpectAttribute>
			struct expected_attribute
	{
		std::string
			  expected_name;
	public:
		using expected_type
				= ExpectedAttribute;
		expected_attribute
			(std::string pName)
				: expected_name(pName) {}
	};

	template
		<typename... T>
			struct expected_attribute_set
	{
	public:
		
	};
}