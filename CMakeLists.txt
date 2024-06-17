cmake_minimum_required(VERSION 3.10)
project(particle_emulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(particle_emulator main.cpp)
target_link_libraries(particle_emulator sfml-system sfml-window sfml-graphics)
