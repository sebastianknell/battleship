cmake_minimum_required(VERSION 3.15)
project(battleship1)

set(CMAKE_CXX_STANDARD 17)

add_executable(battleship1 main.cpp common_types.h controller_t.cpp controller_t.h player_t.cpp player_t.h ship_t.cpp ship_t.h utils.h tablero_t.cpp tablero_t.h casilla_t.cpp casilla_t.h)
