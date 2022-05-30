set(EXECUTABLE 2048)

set(SOURCE_FILES main.cpp
        board/board-manager.cpp
        state-machine/game-state-machine.cpp
        state-machine/states/boot-state.cpp
        state-machine/states/game-state.cpp
        state-machine/states/menu-state.cpp)

set(HEADER_FILES
        board/board-manager.h
        state-machine/game-state-machine.h
        state-machine/state.h
        state-machine/states/boot-state.h
        state-machine/states/game-state.h
        state-machine/states/menu-state.h)

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} lava)

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/src)
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/src/state-machine)
