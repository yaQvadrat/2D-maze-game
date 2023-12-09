#include "GameClient.hh"
#include "../Input/IConfigReader.hh"
#include "../Input/IInputReader.hh"
#include <thread>
#include <string>


GameClient::GameClient(IInputReader& input_reader, IConfigReader &config_reader, IGameView &displayer)
    : input_reader{input_reader}, 
      menu_flag{false},
      input_handler{config_reader},
      game_view{displayer, game}{}

void GameClient::menu()
{
    constexpr int FIRST = 1;
    constexpr int SECOND = 2;
    constexpr int THIRD = 3;
    while (!menu_flag) {}
    switch (input_key)
    {
    case '1':
        game.setLevel(FIRST);
        break;

    case '2':
        game.setLevel(SECOND);
        break;

    case '3':
        game.setLevel(THIRD);
        break;

    case 'q':
        game.setState(GameState::QUIT);
        menu_flag = false;
        return;
    
    default:
        menu_flag = false;
        return;
    }
    game.setState(GameState::IN_PROGRESS);
    menu_flag = false;
}

void GameClient::mainLoop()
{
    game.setState(GameState::MENU);
    std::thread control_input_thread(
        [this]
        {
            while (game.getState() != GameState::QUIT) {
                input_key = input_reader.read();

                if (game.getState() == GameState::IN_PROGRESS) {
                    input_handler.handleInput(input_key, game);
                    continue;
                }

                menu_flag = true;
                while (menu_flag) {}
            }
        }
    );

    while (game.getState() != GameState::QUIT) {
        switch(game.getState())
        {
        case GameState::MENU:
        case GameState::VICTORY:
        case GameState::DEFEAT:
        case GameState::RESTART:
            menu();       
        }
    }

    control_input_thread.join();
}
