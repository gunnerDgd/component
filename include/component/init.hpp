#pragma once
extern "C"
{
#include <component/component.h>
}

namespace synapse::component::bootstrap {
	void
		initialize();
	void
		cleanup   ();
}