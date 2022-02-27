set(EXECUTABLE 2048)

set(SOURCE_FILES main.cpp
        state-machine/game-state-machine.cpp
        state-machine/states/boot-state.cpp
        state-machine/states/menu-state.cpp)

set(HEADER_FILES state-machine/game-state-machine.cpp
        state-machine/state.h
        state-machine/states/boot-state.h
        state-machine/states/menu-state.h)

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} lava)

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/src)
target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/src/state-machine)
