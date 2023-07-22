set(SOURCE_FILES
        game-initializer.cpp
        game-loop.cpp
        board/board-manager.cpp
        state-machine/app-state-machine.cpp
        state-machine/game-state-machine.cpp
        state-machine/states/boot-state.cpp
        state-machine/states/game-state.cpp
        state-machine/states/main-menu-state.cpp
        state-machine/states/menu-state.cpp
        main.cpp)

set(HEADER_FILES
        game-initializer.h
        game-loop.h
        board/board-manager.h
        state-machine/app-state-machine.h
        state-machine/state.h
        state-machine/states/boot-state.h
        state-machine/states/game-state.h
        state-machine/states/main-menu-state.h
        state-machine/states/menu-state.h)

set(EXECUTABLE 2048)
set(LAVA lava)
set(LAVA_SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/lava/src)

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} ${LAVA})

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${EXECUTABLE} PRIVATE ${LAVA_SOURCE_DIR})
#target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/lib/glad/include)

# copy resources to build directory
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${EXECUTABLE}>/res)
