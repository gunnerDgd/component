#include <component/init.hpp>

void
	synapse::component::initialize()
{
	synapse_component_initialize_system
		();
}

void
	synapse::component::cleanup()
{
	synapse_component_cleanup_system
		();
}