cmake_minimum_required(VERSION 3.30)
project(GravitySim)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(GravitySim src/main.cpp
                          src/engine.h
                          src/engine.cpp
                          src/window.h
                          src/window.cpp
                          src/object.h
                          src/object.cpp
                          src/objectmanager.h
                          src/objectmanager.cpp
                          src/moveable.h
                          src/moveable.cpp
                          src/drawable.h
                          src/dragable.h
                          src/collideable.h
)
target_link_libraries(GravitySim PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)
