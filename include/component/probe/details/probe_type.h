#pragma once
#include <structure/list/double_linked.h>
#include <synapse/memory/interface/memory_manager.h>

#include <component/details/component_type.h>
#include <Windows.h>

typedef struct
	__synapse_component_probe_component
{
	synapse_memory_block
		prb_component_mblock;
	volatile uint64_t
		prb_component_refcount;

	__synapse_component*
		prb_component;
	synapse_structure_double_linked_node
		prb_component_node;
} __synapse_component_probe_component;

typedef struct
	__synapse_component_probe_interface
{
	synapse_memory_block
		prb_interface_mblock;
	volatile uint64_t
		prb_interface_refcount;

	__synapse_component_interface*
		prb_interface;
	synapse_structure_double_linked_node
		prb_interface_handle;
} __synapse_component_probe_interface;

typedef struct
	__synapse_component_probe
{
	synapse_memory_block
		 prb_mman_alloc_block;
	synapse_memory_manager
		*prb_mman_probe;

	synapse_structure_double_linked
		 prb_component,
		 prb_component_interface;

	DWORD
		 prb_thread_id;
	HANDLE
		 prb_thread_lock;
} __synapse_component_probe;