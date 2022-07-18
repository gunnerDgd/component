cmake_minimum_required(VERSION 3.0)

project(
    synapse-component-lib-cpp
    VERSION 0.1.0
    LANGUAGES CXX
)

file(
    GLOB_RECURSE src_synapse_component_libcpp CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_library(
    synapse_component_lib_cpp
    STATIC
    ${src_synapse_component_libcpp}
)

target_include_directories(
    synapse_component_lib_cpp
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_include_directories(
    synapse_component_lib_cpp
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    synapse_component_lib_cpp
    synapse_component_dll
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(
        synapse_component_lib_cpp
        PUBLIC
        /std:c++17
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(
        synapse_component_lib_cpp
        PUBLIC
        -std=c++17
    )
endif()