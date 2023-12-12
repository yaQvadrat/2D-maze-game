#ifndef DEFEAT_MESSAGE_HH
#define DEFEAT_MESSAGE_HH

#include "AbstractLogMessage.hh"
#include "../Controller/Coordinates.hh"

class DefeatMessage: public AbstractLogMessage
{
    Coordinates defeat_coordinates;
public:
    DefeatMessage(Coordinates coordinates);
    std::string createMessage() const override;
};

#endif
