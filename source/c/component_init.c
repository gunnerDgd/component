#include <component/component_init.h>
#include <component/probe/details/probe_manip.h>

#include <stdarg.h>

synapse_component_interface
	synapse_component_interface_initialize
		(synapse_component_probe    pProbe, 
		 const char* 				pInterfaceName)
{
	synapse_component_opaque_handle_init
		(synapse_component_interface, hnd_interface,
			__synapse_component_probe_register_interface
				(synapse_component_opaque_handle_reference(pProbe),
					pInterfaceName));

	return
		hnd_interface;
}

synapse_component
	synapse_component_initialize
		(synapse_component_probe     pProbe, 
		 synapse_component_interface pInterface,
		 const char*				 pName,
		 void*						 pArgument)
{
	synapse_component_opaque_handle_init
		(synapse_component, hnd_component,
			__synapse_component_probe_add_component
				(synapse_component_opaque_handle_reference(pProbe),
					synapse_component_opaque_handle_reference(pInterface),
						pName, pArgument));

	return
		hnd_component;
}

void
	synapse_component_interface_cleanup
		(synapse_component_probe pProbe, synapse_component_interface pInterface)
{
	__synapse_component_probe_unregister_interface
		(synapse_component_opaque_handle_reference
			(pProbe),
		 synapse_component_opaque_handle_reference
		 	(pInterface));
}

void
	synapse_component_cleanup
		(synapse_component_probe pProbe, synapse_component pComponent)
{
	__synapse_component_probe_delete_component
		(synapse_component_opaque_handle_reference(pProbe),
			synapse_component_opaque_handle_reference(pComponent));
}