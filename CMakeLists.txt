cmake_minimum_required(VERSION 3.0)

project(
    synapse-component
    VERSION 0.1.0
    LANGUAGES C
)

option(SYNAPSE_COMPONENT_STANDALONE_BUILD OFF)

if(SYNAPSE_COMPONENT_STANDALONE_BUILD)
    set(synapse_component_include_path "${CMAKE_CURRENT_SOURCE_DIR}/../..")
    set(synapse_component_global_include_path "${CMAKE_CURRENT_SOURCE_DIR}/../../../..")
else()
    set(synapse_component_include_path "${CMAKE_CURRENT_SOURCE_DIR}/../..")
    set(synapse_component_global_include_path "${CMAKE_SOURCE_DIR}/../../../..")
endif()

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