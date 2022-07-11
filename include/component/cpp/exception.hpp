#pragma once
#include <type_traits>

namespace synapse::component::exception {
	struct attribute_type_mismatch   {};
	struct attribute_not_found		 {};

	struct component_object_type_mismatch {};
	struct component_creation_failed	  {};
	
	struct interface_not_found		 {};
}