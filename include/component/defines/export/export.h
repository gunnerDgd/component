#pragma once
#ifdef synapse_component_export
#define synapse_component_dll _declspec(dllexport)
#else
#define synapse_component_dll _declspec(dllimport)
#endif