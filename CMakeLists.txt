# CMakeList.txt : CMake project for xEventSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("xEventSystem")

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

# Add source to this project's executable.
add_library (xEventSystem STATIC "Event.cpp" "Event.h" "EventSystem.cpp" "EventSystem.h")

add_executable( EventSystemTest "EventSystemTest.cpp")

target_link_libraries( EventSystemTest xEventSystem)

# TODO: Add tests and install targets if needed.
