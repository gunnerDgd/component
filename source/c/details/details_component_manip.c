#include <component/details/component_manip.h>
#include <synapse/memory/memory.h>
#include <string.h>

void
    __synapse_component_interface_add_attribute
        (__synapse_component_interface* pInterface    ,
         const char*                    pAttributeName, 
         void*                          pAttribute    ,
         void*                          pAttributeAdditional)
{
    __synapse_component_interface_attribute*
        ptr_attribute
            = synapse_system_allocate
                    (sizeof(__synapse_component_interface_attribute));

    ptr_attribute->attr_ptr
        = pAttribute;
    ptr_attribute->attr_additional
        = pAttributeAdditional;
        
    ptr_attribute->attr_name
        = pAttributeName;
    ptr_attribute->attr_node
        = synapse_double_linked_insert_back
            (pInterface->if_attribute,
                &ptr_attribute, sizeof(__synapse_component_interface_attribute*));
}

__synapse_component_interface_attribute*
    __synapse_component_interface_retreive_attribute
        (__synapse_component_interface* pInterface, const char* pName)
{
    synapse_double_linked_node
        ptr_seek
            = synapse_double_linked_node_begin
                    (pInterface->if_attribute);

    for( ; ptr_seek.opaque
         ; ptr_seek = synapse_double_linked_node_next(ptr_seek))
    {
        __synapse_component_interface_attribute*
            ptr_attr
                = *(__synapse_component_interface_attribute**)
                        synapse_double_linked_node_data
                            (ptr_seek);

        if(strcmp(ptr_attr->attr_name, pName) == 0)
            return 
                ptr_attr;
   }

   return NULL;
}

void
    __synapse_component_interface_delete_attribute
        (__synapse_component_interface* pInterface, 
         const char*                    pName)
{
    __synapse_component_interface_attribute*
        ptr_seek
            = __synapse_component_interface_retreive_attribute
                    (pInterface, pName);

    if(!ptr_seek)
        return NULL;

    synapse_double_linked_erase_at
        (pInterface->if_attribute, ptr_seek->attr_node);
    synapse_system_deallocate
        (ptr_seek);
}