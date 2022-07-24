cmake_minimum_required(VERSION 3.0)

project(
    synapse-component
    VERSION 0.1.0
    LANGUAGES C
)

add_subdirectory(source/c)
add_subdirectory(source/shared_libs)


add_dependencies(
    synapse_component_dll
    synapse_component_lib
)