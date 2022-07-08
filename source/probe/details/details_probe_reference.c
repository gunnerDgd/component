#include <component/probe/details/probe_reference.h>
#include <Windows.h>

uint64_t
	__synapse_component_probe_reference_interface
		(__synapse_component_probe_interface* pInterface)
{
	InterlockedIncrement64
		(&pInterface->prb_interface_refcount);

	return
		pInterface->prb_interface_refcount;
}

uint64_t
	__synapse_component_probe_dereference_interface
		(__synapse_component_probe_interface* pInterface)
{
	InterlockedDecrement64
		(&pInterface->prb_interface_refcount);

	return
		pInterface->prb_interface_refcount;
}

uint64_t
	__synapse_component_probe_reference_component
		(__synapse_component_probe_component* pComponent)
{
	InterlockedIncrement64
		(&pComponent->prb_component_refcount);

	return
		pComponent->prb_component_refcount;
}

uint64_t
	__synapse_component_probe_dereference_component
		(__synapse_component_probe_component* pComponent)
{
	InterlockedDecrement64
		(&pComponent->prb_component_refcount);

	return
		pComponent->prb_component_refcount;
}