#include <component/component_manip.h>

#include <component/details/component_type.h>
#include <component/details/component_manip.h>

#include <component/probe/details/probe_type.h>
#include <component/probe/details/probe_reference.h>

#include <string.h>

uint64_t
	synapse_component_reference
		(synapse_component pComponent)
{
	return
		__synapse_component_probe_reference_component
			(synapse_component_opaque_handle_reference
				(pComponent));
}

uint64_t
	synapse_component_dereference
		(synapse_component pComponent)
{
	return
		__synapse_component_probe_dereference_component
			(synapse_component_opaque_handle_reference
				(pComponent));
}

void*
	synapse_component_retrieve_entity
		(synapse_component pComponent)
{
	return
		synapse_component_opaque_handle_cast
			(pComponent, __synapse_component_probe_component*)
				->prb_component->component_entity;
}

void
	synapse_component_add_attribute
		(synapse_component_interface pInterface, 
		 const char*				 pAttributeName, 
		 void*						 pAttributeData, 
		 void*						 pAttributeAdditional)
{
	__synapse_component_interface_add_attribute
		(synapse_component_opaque_handle_cast
			(pInterface, __synapse_component_probe_interface*)
				->prb_interface, pAttributeName, 
					pAttributeData, pAttributeAdditional);
}

void
	synapse_component_delete_attribute
		(synapse_component_interface pInterface, const char* pName)
{
	__synapse_component_interface_delete_attribute
		(synapse_component_opaque_handle_cast
			(pInterface, __synapse_component_probe_interface*)
				->prb_interface, pName);
}

synapse_component_interface_attribute
	synapse_component_retrieve_attribute
		(synapse_component_interface pInterface, const char* pName)
{
	synapse_component_opaque_handle_init
		(synapse_component_interface_attribute, hnd_interface,
			__synapse_component_interface_retreive_attribute
				(synapse_component_opaque_handle_cast
					(pInterface, __synapse_component_probe_interface*)
						->prb_interface, pName));

	return
		hnd_interface;
}

void*
	synapse_component_retrieve_attribute_data
		(synapse_component_interface_attribute pAttribute)
{
	return
		synapse_component_opaque_handle_cast
			(pAttribute, __synapse_component_interface_attribute*)
				->attr_ptr;
}

void*
	synapse_component_retrieve_attribute_additional
		(synapse_component_interface_attribute pAttribute)
{
	return
		synapse_component_opaque_handle_cast
			(pAttribute, __synapse_component_interface_attribute*)
				->attr_additional;
}