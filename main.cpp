#include "Game/GameClient.hh"
#include "Input/ConsoleInputReader.hh"
#include "Input/FileConfigReader.hh"
#include "Game/ConsoleGameView.hh"
#include <iostream>



int main()
{
    ConsoleGameView displayer;
    ConsoleInputReader input_reader;
    FileConfigReader config_reader("../Input/CONFIG");
    try
    {
        GameClient client(input_reader, config_reader, displayer);
        client.mainLoop();
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << ex.what() << "\n";
        return 1;
    }
    catch (const std::logic_error &ex)
    {
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}
