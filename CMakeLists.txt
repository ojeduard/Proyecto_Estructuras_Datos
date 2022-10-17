cmake_minimum_required(VERSION 3.21)
project(Proyecto_Estructuras_Datos)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Proyecto_Estructuras_Datos main.cpp src/DataBase.cpp src/DataBase.h src/LetterBlock.cpp src/LetterBlock.h src/Player.cpp src/Player.h src/Node.cpp src/Node.h src/Board.cpp src/Board.h src/Game.cpp src/Game.h src/GameMenu.cpp src/GameMenu.h)
