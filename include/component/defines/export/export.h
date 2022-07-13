#pragma once
#ifdef synapse_component_export_mode
#define synapse_component_dll _declspec(dllexport)
#else
#define synapse_component_dll _declspec(dllimport)
#endif