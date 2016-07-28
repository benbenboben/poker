cmake_minimum_required(VERSION 3.3)
project(poker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/card.cpp
    src/card.h
    src/deck.cpp
    src/deck.h
    src/main.cpp
    src/misc.cpp
    src/misc.h
    src/poker_hand.cpp
    src/poker_hand.h)

add_executable(poker ${SOURCE_FILES})