#include <component/cpp/meta_object.hpp>

namespace synapse::component {
	template
		<typename ObjectType>
	class component
	{
	public:
		using name_type
					= const char*;
		using value_type
					= ObjectType;
		using reference
					= ObjectType&;
		using pointer
					= ObjectType*;
	public:
		component
			(name_type pName, meta_object& pMetaobject)
		{
			static_assert
				(!std::is_void_v<value_type>,
					"[synapse_component][assert] component<void> is not allowed.\n");

			if(typeid(value_type).hash_code()
					!= (std::uint64_t)pMetaobject.__M_metaobj_attribute.type_additional)
				throw
					exception::component_object_type_mismatch {};

			__M_component_handle
					= synapse_create_component
							(pMetaobject.__M_metaobj_handle,
									pName, 1, &pMetaobject);

			if(!synapse_component_opaque_handle_reference
					(__M_component_handle))
				throw 
					exception::component_creation_failed {};
		}
		component
			(const component& pCopy)
				: __M_component_handle
						(pCopy.__M_component_handle) 
							{ synapse_reference_component(__M_component_handle); }
		component
			(const component&& pMove)
				: __M_component_handle
						(pMove.__M_component_handle) {}

		~component
			()
				{ synapse_delete_component(__M_component_handle); }

	public:
		reference
			get_object
				() 
					{ return *reinterpret_cast<pointer>
									(synapse_retrieve_object(__M_component_handle)); }

	private:
		synapse_component
			__M_component_handle;
	};
}