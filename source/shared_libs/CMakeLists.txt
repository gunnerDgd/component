cmake_minimum_required(VERSION 3.0)

project(
    synapse-component-dll
    VERSION 0.1.0
    LANGUAGES C
)

add_library(
    synapse_component_dll
    SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/component.c
)

target_include_directories(
    synapse_component_dll
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_include_directories(
    synapse_component_dll
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    synapse_component_dll
    synapse_component_lib
    synapse_memory_dll
    synapse_structure_dll
)

target_compile_options(
    synapse_component_dll PRIVATE /Dsynapse_component_export_mode
)

add_dependencies(
    synapse_component_dll
    synapse_memory_dll
)