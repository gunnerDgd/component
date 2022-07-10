#include <component/init.hpp>

void
	synapse::component::bootstrap::initialize()
{
	synapse_component_initialize_system
		();
}

void
	synapse::component::bootstrap::cleanup()
{
	synapse_component_cleanup_system
		();
}