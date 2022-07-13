cmake_minimum_required(VERSION 3.0)

project(
    synapse-component
    VERSION 0.1.0
    LANGUAGES C
)

add_subdirectory(source/c)
add_subdirectory(source/shared_libs)
add_subdirectory(source/cpp)

add_dependencies(
    synapse_component_dll
    synapse_component_lib
)

add_dependencies(
    synapse_component_lib_cpp
    synapse_component_lib
    synapse_component_dll
)

target_link_libraries(
    synapse_component_dll
    synapse_component_lib
)

target_link_libraries(
    synapse_component_lib_cpp
    synapse_component_dll
)