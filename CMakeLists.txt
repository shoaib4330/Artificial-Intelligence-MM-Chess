cmake_minimum_required(VERSION 3.6)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

set(BUILD1 primary)
set(SOURCE_FILES Source/main.cpp Source/ChessState.cpp Source/ChessMove.cpp Source/ChessPlayer.cpp Headers/ChessProblem.h Headers/PlayerChessCustom.h)
add_executable(Chess ${SOURCE_FILES})