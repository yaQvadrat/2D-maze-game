#include "Game/GameClient.hh"
#include "Input/ConsoleInputReader.hh"
#include "Input/FileConfigReader.hh"





int main()
{
    ConsoleInputReader input_reader;
    FileConfigReader config_reader("../Input/CONFIG");
    GameClient client(input_reader, config_reader);
    client.mainLoop();
    return 0;
}
