#include "NewGameMessage.hh"
#include <sstream>

NewGameMessage::NewGameMessage(int width, int height, Coordinates coordinates)
    : width{width}, height{height}, start_coordinates{coordinates}{}

std::string NewGameMessage::createMessage() const
{
    std::ostringstream buffer;
    buffer << "NEW GAME || FIELD: " << width << "x" << height << " || START: " << start_coordinates;
    return buffer.str();
}
