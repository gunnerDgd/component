#include <component/probe/details/probe_init.h>
#include <synapse/memory/memory.h>

__synapse_component_probe*
	__synapse_component_probe_initialize
		(synapse_memory_manager* pMmanProbe)
{
	__synapse_component_probe*
		ptr_probe
			= synapse_system_allocate
					(sizeof(__synapse_component_probe));

	ptr_probe->prb_mman_probe
		= pMmanProbe;

	ptr_probe->prb_component
		= synapse_initialize_double_linked
				(pMmanProbe);
	ptr_probe->prb_component_interface
		= synapse_initialize_double_linked
				(pMmanProbe);
	
	ptr_probe->prb_thread_id
		= GetCurrentThreadId();
	ptr_probe->prb_thread_lock
		= CreateMutex(NULL, TRUE, NULL);

	return
		ptr_probe;
}

void
	__synapse_component_probe_cleanup
		(__synapse_component_probe* pProbe)
{
	if(GetCurrentThreadId()
			!= pProbe->prb_thread_id)
				return;

	synapse_cleanup_double_linked
		(pProbe->prb_component);
	synapse_cleanup_double_linked
		(pProbe->prb_component_interface);
	synapse_system_deallocate
		(pProbe);
}