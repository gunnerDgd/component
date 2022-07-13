#include <component/component_manip.h>
#include <component/details/component_type.h>

#include <component/probe/details/probe_type.h>
#include <component/probe/details/probe_reference.h>

#include <string.h>

void*
	synapse_component_retrieve_object
		(synapse_component pComponent)
{
	return
		synapse_component_opaque_handle_cast
			(pComponent, __synapse_component_probe_component*)
				->prb_component->comp_interface;
}

synapse_component_metadata_type*
	synapse_component_retrieve_type
		(synapse_component_interface pInterface)
{
	synapse_component_metadata*
		ptr_metadata
			= &synapse_component_opaque_handle_cast
					(pInterface, __synapse_component_probe_interface*)
						->prb_interface->if_metadata;

	return 
		ptr_metadata->component_type;
}
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