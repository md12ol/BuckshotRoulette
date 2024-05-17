cmake_minimum_required(VERSION 3.22)
project(BuckshotRoulette)

set(CMAKE_CXX_STANDARD 23)

add_executable(BuckshotRoulette main.cpp
        Game.h
        Game.cpp
        Round.h
        Round.cpp
        Clip.h
        Clip.cpp
        Player.h
        Player.cpp
        Human.h
        Human.cpp
        Computer.h
        Computer.cpp
        Item.h
        Item.cpp)
