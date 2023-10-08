cmake_minimum_required(VERSION 3.2)


project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PLAYER Player/Player.cpp)
set(CONTROLLER Controller/Coordinates.cpp Controller/PlayerController.cpp)
set(CHARACTERISTIC Characteristic/Characteristic.cpp Characteristic/Health.cpp Characteristic/Points.cpp)

add_executable(main main.cpp ${PLAYER} ${CONTROLLER} ${CHARACTERISTIC})
