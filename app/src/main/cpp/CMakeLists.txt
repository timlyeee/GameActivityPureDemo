cmake_minimum_required(VERSION 3.8)

project(GameActivityDemo)

find_package(game-activity REQUIRED CONFIG)

set(PROJ_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)
add_library(game SHARED
        ${PROJ_SOURCES})

target_link_libraries(game
    android
    game-activity::game-activity
)
