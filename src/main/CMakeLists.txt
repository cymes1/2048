set(SOURCE_FILES
        domains/game-domain.cpp
        )

set(HEADER_FILES
        domains/game-domain.h
        )

add_library(${MAIN} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${MAIN} ${LAVA})

target_include_directories(${MAIN} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${MAIN} PRIVATE ${LAVA_SOURCE_DIR})
