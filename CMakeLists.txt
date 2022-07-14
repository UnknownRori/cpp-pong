cmake_minimum_required(VERSION 3.0.0)
project(pong VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Include Directory
include_directories(./vendor/sfml/include)
include_directories(./include)

# SFML Library
find_library(SFML_SYSTEM libsfml-system.a ./vendor/sfml/lib)
find_library(SFML_MAIN libsfml-main.a ./vendor/sfml/lib)
find_library(SFML_WINDOW libsfml-window.a ./vendor/sfml/lib)
find_library(SFML_GRAPHICS libsfml-graphics.a ./vendor/sfmllib)
find_library(SFML_AUDIO libsfml-audio.a ./vendor/sfmllib)

# Main Compilation
add_executable(pong main.cpp ./src/Application.cpp ./src/GameManager.cpp)
target_link_libraries(pong ${SFML_MAIN} ${SFML_SYSTEM} ${SFML_WINDOW} ${SFML_GRAPHICS} ${SFML_AUDIO})