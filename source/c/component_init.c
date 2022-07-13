#include <component/component_init.h>
#include <component/probe/details/probe_manip.h>

#include <stdarg.h>

synapse_component_interface
	synapse_component_interface_initialize
		(synapse_component_probe    pProbe, 
		 synapse_component_metadata pMetadata, 
		 synapse_component_traits   pTraits)
{
	synapse_component_opaque_handle_init
		(synapse_component_interface, hnd_interface,
			__synapse_component_probe_register_interface
				(synapse_component_opaque_handle_reference(pProbe),
					pMetadata, pTraits));

	return
		hnd_interface;
}

synapse_component
	synapse_component_initialize
		(synapse_component_probe     pProbe, 
		 synapse_component_interface pInterface, 
		 const char*				 pName, int pArgCount, ...)
{
	va_list ptr_args;
	va_start
		(ptr_args, pArgCount);

	return
		synapse_component_initialize_from_vargs
			(pProbe, pInterface, pName, ptr_args);
}

synapse_component
	synapse_component_initialize_from_vargs
		(synapse_component_probe     pProbe, 
		 synapse_component_interface pInterface,
		 const char*				 pName,
		 va_list					 pArgument)
{
	synapse_component_opaque_handle_init
		(synapse_component, hnd_component,
			__synapse_component_probe_create_component
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