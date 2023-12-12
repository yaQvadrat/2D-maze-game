#include "CommandMessage.hh"
#include "../Command/ExitCommand.hh"
#include "../Command/MoveCommand.hh"
#include "../Command/RestartCommand.hh"
#include <sstream>
#include <typeinfo>


void CommandMessage::commandToString(const std::shared_ptr<ICommand> &command)
{
    if (!command) {
        command_type = "UNDEFINED COMMAND";
        return;
    }
    
    if (typeid(*command) == typeid(ExitCommand)) {
        command_type = "EXIT";
    } else if (typeid(*command) == typeid(RestartCommand)) {
        command_type = "RESTART";
    } else if (typeid(*command) == typeid(MoveCommand)) {
        Direction direction = static_cast<MoveCommand*>(command.get())->getDirection();
        switch (direction)
        {
        case Direction::UP:
            command_type = "MVUP";
            break;
        
        case Direction::DOWN:
            command_type = "MVDOWN";
            break;
        
        case Direction::LEFT:
            command_type = "MVLEFT";
            break;
        
        case Direction::RIGHT:
            command_type = "MVRIGHT";
            break;
        }
    }
}

CommandMessage::CommandMessage(char key, const std::shared_ptr<ICommand> &command): key{key}
{
    commandToString(command);
}

std::string CommandMessage::createMessage() const
{
    std::ostringstream buffer;
    buffer << "KEY PRESSED: " << key << " || COMMAND: " << command_type;
    return buffer.str();
}