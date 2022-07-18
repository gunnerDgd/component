cmake_minimum_required(VERSION 3.0)

project(
    synapse-component-lib
    VERSION 0.1.0
    DESCRIPTION "Component Support Layer for Synapse Framework"
    LANGUAGES CXX
)

file(
    GLOB_RECURSE src_synapse_component_lib CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
    synapse_component_lib
    STATIC
    ${src_synapse_component_lib}
)

target_include_directories(
    synapse_component_lib
    PUBLIC
    ${synapse_component_include_path}/include
)

target_include_directories(
    synapse_component_lib
    PUBLIC
    ${synapse_component_global_include_path}/include
)

target_include_directories(
    synapse_component_lib
    PUBLIC
    ${synapse_component_global_include_path}/submodules/synapse-structure/include
)