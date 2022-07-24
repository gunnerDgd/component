#include <component/details/component_init.h>

void
    __synapse_component_interface_add_attribute
        (__synapse_component_interface*,
                const char*, void*, void*);

void
    __synapse_component_interface_delete_attribute
        (__synapse_component_interface*, const char*);

__synapse_component_interface_attribute*
    __synapse_component_interface_retreive_attribute
        (__synapse_component_interface*, const char*);