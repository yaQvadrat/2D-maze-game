#ifndef GAME_CLIENT_HH
#define GAME_CLIENT_HH

#include "../Input/InputHandler.hh"
#include "Game.hh"
#include "GameViewObserver.hh"
#include <memory>

class IInputReader;
class IConfigReader;
class IGameView;

class GameClient
{
    IInputReader &input_reader;
    InputHandler input_handler;
    Game game;
    GameViewObserver game_view;
    bool menu_flag;
    char input_key;

    void menu();

public:
    GameClient(IInputReader &input_reader, IConfigReader &config_reader, IGameView &displayer);

    void mainLoop();
};

#endif
