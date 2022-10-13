set(SOURCE_FILES
        game-initializer.cpp
        main.cpp)

set(HEADER_FILES
        game-initializer.h)

set(EXECUTABLE 2048)
set(LAVA lava)
set(LAVA_SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/lava/src)

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} ${LAVA})

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${EXECUTABLE} PRIVATE ${LAVA_SOURCE_DIR})
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/lib/glm)
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/lib/glad/include)

# copy resources to build directory
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${EXECUTABLE}>/res)
