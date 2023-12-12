#ifndef WIN_MESSAGE_HH
#define WIN_MESSAGE_HH

#include "AbstractLogMessage.hh"
#include <iostream>

class WinMessage: public AbstractLogMessage
{
    int health;
    int points;
public:
    WinMessage(int health, int points);
    std::string createMessage() const override;
};

#endif
