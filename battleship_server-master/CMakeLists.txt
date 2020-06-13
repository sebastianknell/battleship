cmake_minimum_required(VERSION 3.12.3)
project(battleship_server)

set(CMAKE_CXX_STANDARD 17)
set( CMAKE_VERBOSE_MAKEFILE on)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS -pthread)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Wextra")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -Wextra")
endif()

add_executable(battleship_server main.cpp common_types.h player.cpp player.h controller.cpp controller.h)
if(UNIX AND NOT APPLE)
    target_link_libraries(battleship_server stdc++fs)
endif()


