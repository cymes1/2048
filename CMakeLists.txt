cmake_minimum_required(VERSION 3.19)
project(2048)

set(CMAKE_CXX_STANDARD 20)

if(WIN32)
    add_link_options(-static-libgcc -static-libstdc++)
endif()

# set the output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)

# preprocessor directives
if(WIN32)
    add_compile_definitions(LAVA_WINDOWS)
else()
    add_compile_definitions(LAVA_LINUX)
endif()

set(TARGET debug)
if(${TARGET} STREQUAL debug)
    add_compile_definitions(LAVA_LOG_ENABLED)
    # add_compile_definitions(LAVA_LOG_VERBOSE)
elseif(${TARGET} STREQUAL release)
endif()

add_subdirectory(lib)
add_subdirectory(src)