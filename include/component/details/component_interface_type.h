#include <component/interface/component.h>

#include <synapse/structure/list/double_linked.h>
#include <synapse/memory/interface/memory_manager.h>

typedef struct
	__synapse_component_interface_attribute
{
    union
    {
	    void*   attr_ptr;
        void* (*attr_function_ptr)(void*);
    };
	
	const char*
		attr_name;
	void*
		attr_additional;

	synapse_double_linked_node
		attr_node;
} __synapse_component_interface_attribute;

typedef struct
	__synapse_component_interface
{
	synapse_double_linked
        if_attribute;
    const char*
        if_name;
} __synapse_component_interface;