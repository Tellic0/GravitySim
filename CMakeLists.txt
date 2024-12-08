cmake_minimum_required(VERSION 3.29)
project(GravitySim)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(IMGUI
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.87
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(IMGUI)

set(IMGUI_DIR ${imgui_SOURCE_DIR})

FetchContent_Declare(ImGui-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
        GIT_TAG v2.6
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(ImGui-SFML)


#find_package(SFML COMPONENTS graphics window system audio REQUIRED)

add_executable(GravitySim src/main.cpp
        src/engine.cpp
        src/engine.h
        src/window.cpp
        src/window.h
        src/globals.h
        src/objectmanager.cpp
        src/objectmanager.h
        src/object.cpp
        src/object.h
        src/moveable.h
        src/test.cpp
        src/test.h)

target_link_libraries(GravitySim PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)
target_link_libraries(GravitySim PRIVATE ImGui-SFML::ImGui-SFML)
