cmake_minimum_required(VERSION 3.2)


project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

set(PLAYER Player/Player.cpp)
set(CONTROLLER Controller/Coordinates.cpp Controller/PlayerController.cpp Controller/Direction.cpp)
set(CHARACTERISTIC Characteristic/Characteristic.cpp Characteristic/Health.cpp Characteristic/Points.cpp)
set(FIELD Field/Field.cpp Field/Cell.cpp Field/FieldCreator.cpp)
set(EVENT Event/IEvent.cpp Event/PointsEvent.cpp Event/TrapEvent.cpp Event/ThrowAsideEvent.cpp)
set(INPUT Input/IConfigReader.cpp Input/FileConfigReader.cpp Input/IInputReader.cpp
    Input/ConsoleInputReader.cpp Input/InputHandler.cpp)
set(GAME Game/Game.cpp Game/GameClient.cpp)
set(COMMAND Command/ExitCommand.cpp Command/ICommand.cpp Command/MoveCommand.cpp Command/RestartCommand.cpp)
set(OBSEVER Observer/IObserver.cpp Observer/ISubject.cpp)
set(GAMEVIEW Game/IGameView.cpp Game/GameViewObserver.cpp Game/ConsoleGameView.cpp)
set(LOGGERMSG Logger/AbstractLogMessage.cpp Logger/WinMessage.cpp Logger/DefeatMessage.cpp
    Logger/NewGameMessage.cpp Logger/CommandMessage.cpp Logger/NotCommandMessage.cpp)
set(LOGGER Logger/ILogger.cpp Logger/ILoggable.cpp Logger/ILoggerOutput.cpp
    Logger/GameLogger.cpp Logger/FileLoggerOutput.cpp Logger/ConsoleLoggerOutput.cpp)

add_executable(main main.cpp    ${PLAYER}
                                ${CONTROLLER}
                                ${CHARACTERISTIC}
                                ${FIELD}
                                ${EVENT}
                                ${INPUT}
                                ${GAME}
                                ${COMMAND}
                                ${GAMEVIEW}
                                ${OBSERVER}
                                ${LOGGERMSG}
                                ${LOGGER})
