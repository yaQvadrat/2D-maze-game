#ifndef COMMAND_MESSAGE_HH
#define COMMAND_MESSAGE_HH

#include "AbstractLogMessage.hh"
#include <memory>

class ICommand;

class CommandMessage: public AbstractLogMessage
{
    char key;
    std::string command_type;
   
    void commandToString(const std::shared_ptr<ICommand> &command);
public:
    CommandMessage(char key, const std::shared_ptr<ICommand> &command);
    std::string createMessage() const override;
};

#endif
