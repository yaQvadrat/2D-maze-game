#ifndef NOT_COMMAND_MESSAGE_HH
#define NOT_COMMAND_MESSAGE_HH

#include "AbstractLogMessage.hh"

class NotCommandMessage: public AbstractLogMessage
{
    char key;
public:
    NotCommandMessage(char key);
    std::string createMessage() const override;
};

#endif
