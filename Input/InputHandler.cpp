#include "InputHandler.hh"
#include "IConfigReader.hh"
#include "../Command/ICommand.hh"
#include <iostream>

InputHandler::InputHandler(IConfigReader &config_reader)
{
    key_mapping = config_reader.readConfig();
}

void InputHandler::handleInput(char key, Game &game)
{
    key = std::toupper(key);
    if (key_mapping.contains(key))
        key_mapping.at(key)->execute(game);
}
