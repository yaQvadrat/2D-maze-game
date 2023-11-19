#include "GameClient.hh"
#include "../Input/IConfigReader.hh"
#include "../Input/IInputReader.hh"
#include <thread>
#include <string>

GameClient::GameClient(IInputReader& input_reader, IConfigReader &config_reader)
    : input_reader{input_reader}, config_reader{config_reader},
      input_handler{config_reader}{}

void GameClient::menu()
{
    constexpr const char *VICTORY_SIGNAL = "VICTORY\n\n";
    constexpr const char *DEFEAT_SIGNAL = "DEFEAT\n\n";
    constexpr int FIRST = 1;
    constexpr int SECOND = 2;
    GameState state = game.getState();
    std::string extra_output;
    switch (state)
    {
    case GameState::VICTORY:
        extra_output = VICTORY_SIGNAL;
        break;
    
    case GameState::DEFEAT:
        extra_output = DEFEAT_SIGNAL;
        break;
    }
    std::cout << extra_output << "MENU\n1. First Level\n2. Second Level\n3. Any another key to Exit\n";
    char choice = input_reader.read();
    switch (choice)
    {
    case '1':
        game.setLevel(FIRST);
        break;

    case '2':
        game.setLevel(SECOND);
        break;

    default:
        game.setState(GameState::QUIT);
        return;
    }
    std::cout << "\nLevel ready\n";
    game.setState(GameState::IN_PROGRESS);
}

void GameClient::mainLoop()
{
    std::thread game_status_thread(
        [this]
        {
            while (game.getState() != GameState::QUIT) {
                switch(game.getState())
                {
                case GameState::MENU:
                case GameState::VICTORY:
                case GameState::DEFEAT:
                    menu();
                }
            }
        }
    );
    game_status_thread.detach();

    std::thread control_input_thread(
        [this]
        {
            char key;
            while (game.getState() != GameState::QUIT) {
                if (game.getState() == GameState::IN_PROGRESS) {
                    key = input_reader.read();
                    input_handler.handleInput(key, game);
                }
            }
        }
    );
    control_input_thread.join();
}