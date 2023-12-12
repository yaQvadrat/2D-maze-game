#ifndef NEW_GAME_MESSAGE_HH
#define NEW_GAME_MESSAGE_HH

#include "AbstractLogMessage.hh"
#include "../Controller/Coordinates.hh"

class NewGameMessage: public AbstractLogMessage
{
    int width;
    int height;
    Coordinates start_coordinates;
public:
    NewGameMessage(int width, int height, Coordinates coordinates);
    std::string createMessage() const override;
};

#endif
