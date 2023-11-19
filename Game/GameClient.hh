#ifndef GAME_CLIENT_HH
#define GAME_CLIENT_HH

#include "../Input/InputHandler.hh"
#include "Game.hh"

class IInputReader;
class IConfigReader;

class GameClient
{
    IInputReader &input_reader;
    IConfigReader &config_reader;
    InputHandler input_handler;
    Game game;

public:
    GameClient(IInputReader &input_reader, IConfigReader &config_reader);

    void menu();

    void mainLoop();
};

#endif
