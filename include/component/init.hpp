#pragma once
extern "C"
{
#include <component/component.h>
}

namespace synapse::component {
	void
		initialize();
	void
		cleanup   ();
}