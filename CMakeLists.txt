cmake_minimum_required(VERSION 3.21)
project(PokemonGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(PokemonGame main.cpp Elemental.cpp Elemental.h Creature.cpp Creature.h)
