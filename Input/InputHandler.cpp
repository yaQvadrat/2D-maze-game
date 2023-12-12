#include "InputHandler.hh"
#include "IConfigReader.hh"
#include "../Command/ICommand.hh"
#include "../Logger/ILogger.hh"
#include "../Logger/CommandMessage.hh"
#include "../Logger/NotCommandMessage.hh"
#include <iostream>

InputHandler::InputHandler(IConfigReader &config_reader)
{
    key_mapping = config_reader.readConfig();
}

void InputHandler::handleInput(char key, Game &game)
{
    key = std::toupper(key);
    if (key_mapping.contains(key)) {
        sendLogMessage(CommandMessage(key, key_mapping.at(key)));
        key_mapping.at(key)->execute(game);
    } else {
        sendLogMessage(NotCommandMessage(key));
    }
}

void InputHandler::attachLogger(ILogger *logger)
{
    logger_list.push_back(logger);
}

void InputHandler::detachLogger(ILogger *logger)
{
    logger_list.remove(logger);
}

void InputHandler::sendLogMessage(const AbstractLogMessage &msg)
{
    for (auto logger: logger_list)
        logger->logMessage(msg);
}
