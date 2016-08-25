cmake_minimum_required(VERSION 3.3)
project(poker)
include_directories(/usr/local/Cellar/tbb/4.4-20160128/include)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++-5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O4")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")

set(SOURCE_FILES
    src/card.cpp
    src/card.h
    src/deck.cpp
    src/deck.h
    src/main.cpp
    src/misc.cpp
    src/misc.h
    src/poker_hand.cpp
    src/poker_hand.h src/poker_game.cpp src/poker_game.h)

add_executable(poker ${SOURCE_FILES})