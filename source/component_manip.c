#include <component/component_manip.h>
#include <component/details/component_type.h>
#include <component/probe/details/probe_type.h>

void*
	synapse_component_retrieve_object
		(synapse_component pComponent)
{
	return
		synapse_component_opaque_handle_cast
			(pComponent, __synapse_component_probe_component*)
				->prb_component->comp_interface;
}

synapse_component_meta_object
	synapse_component_retrieve_meta_object
		(synapse_component pComponent)
{
	return
		synapse_component_opaque_handle_cast
			(pComponent, __synapse_component_probe_component*)
				->prb_component->comp_interface
					->if_metadata.component_meta_object;
}