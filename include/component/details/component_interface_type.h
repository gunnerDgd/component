#include <component/interface/component.h>
#include <structure/list/double_linked.h>

#include <synapse/memory/interface/memory_manager.h>

typedef struct
	__synapse_component_interface_attribute
{
    union
    {
	    void*
		      attr_ptr;
        void*
            (*attr_function_ptr)(void*);
    };
	const char*
		attr_name;
	void*
		attr_additional;

	synapse_memory_block
		attr_memblock;
	synapse_structure_double_linked_node
		attr_node;
} __synapse_component_interface_attribute;

typedef struct
	__synapse_component_interface
{
	synapse_memory_block
		if_alloc_block;
	synapse_structure_double_linked
        if_attribute;
    const char*
        if_name;
} __synapse_component_interface;