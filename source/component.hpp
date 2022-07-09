#include <component/prototype.hpp>

namespace synapse::component {
	
	template <typename... T>
	class component;

	template
			<typename    ComponentType,
			 typename... ProtoTypeArgument>
	class component
				<ComponentType,
					prototype<ProtoTypeArgument...>>
	{
	public:
		using prototype_type
					= prototype<ProtoTypeArgument...>;
		using object_type
					= typename prototype_type::object_type;
		using name_type
					= const char*;

	public:
		component
			(name_type, prototype_type&);
		component
			(name_type);
		~component
			();

	public:
		object_type&
			get_object();

	private:
		synapse_component
			__M_component_handle;
	};
}

template <typename T, typename... U>
	synapse::component::component<T, synapse::component::prototype<U...>>::component
		(name_type pName, prototype_type& pPrototype)
			: __M_component_handle
					(synapse_create_component
						(pPrototype.__M_prototype_handle, pName, 1, 
							&pPrototype.__M_prototype_metaobj))
{
	
}

template <typename T, typename... U>
	synapse::component::component<T, synapse::component::prototype<U...>>::component
		(name_type pName)
			: __M_component_handle
					(synapse_retrieve_component(pName))
{
}

template <typename T, typename... U>
	synapse::component::component<T, synapse::component::prototype<U...>>::~component()
{
	synapse_delete_component
		(__M_component_handle);
}

template <typename T, typename... U>
typename synapse::component::component<T, synapse::component::prototype<U...>>::object_type&
	synapse::component::component<T, synapse::component::prototype<U...>>::get_object()
{
	return
		*reinterpret_cast<object_type*>
			(synapse_component_object
					(__M_component_handle));
}