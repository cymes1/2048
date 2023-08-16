set(SOURCE_FILES
        board/board-manager.cpp
        main/state-machine/app-state-machine.cpp
        main/state-machine/states/game-state.cpp
        main/state-machine/states/main-menu-state.cpp
        main/state-machine/states/menu-state.cpp
        main.cpp)

set(HEADER_FILES
        board/board-manager.h
        main/state-machine/app-state-machine.h
        main/state-machine/states/game-state.h
        main/state-machine/states/main-menu-state.h
        main/state-machine/states/menu-state.h)

set(EXECUTABLE 2048)
set(LAVA lava)
set(LAVA_SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/lava/src)
set(MAIN mainLib)

add_subdirectory(main)

add_executable(${EXECUTABLE} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${EXECUTABLE} ${LAVA})
target_link_libraries(${EXECUTABLE} ${MAIN})

target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${EXECUTABLE} PRIVATE ${LAVA_SOURCE_DIR})
#target_include_directories(${EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/lava/lib/glad/include)

# copy resources to build directory
add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${EXECUTABLE}>/res)
