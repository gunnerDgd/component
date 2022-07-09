#pragma once
#include <component/exception.hpp>
#include <string>

namespace synapse::modules {
	template <typename ExportClass>
	void export_class(std::string);
}