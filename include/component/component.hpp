#pragma once
extern "C"
{
#include <component/component.h>
}

#include <component/exception.hpp>

#include <string>

#include <typeinfo>
#include <type_traits>

namespace synapse::component {
	class component
	{
		struct type_data;
		component(synapse_component_interface);
	public:
		using name_type
				= std::string;
		using native_handle_type
				= synapse_component_interface;

	public:
		static component
				import_from(name_type);
		template <typename ClassType, typename... ConstructArgs>
		static void
				export_to  (name_type);
	private:
		native_handle_type
			__M_component_interface;
	};

	struct component::type_data
	{
		uint64_t
			type_hashcode;
	};
}

template <typename ClassType, typename... ConstructArgs>
void
	synapse::component::component::export_to
		(name_type pName)
{
	static component::type_data
				hnd_type;

	hnd_type.type_hashcode
		= typeid(ClassType).hash_code();
	
	synapse_component_metadata
		hnd_metadata;
	hnd_metadata.component_name
		= pName;
	hnd_metadata.component_name_length
		= std::strlen(pName);
	hnd_metadata.component_type
		= reinterpret_cast<void*>(&hnd_type);

	synapse_component_traits
		hnd_traits;

	hnd_traits.cleanup
		= [](va_list pArgs)
				{ return 
					std::apply
						([]()) }
}