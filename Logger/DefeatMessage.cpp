#include "DefeatMessage.hh"
#include <sstream>

DefeatMessage::DefeatMessage(Coordinates coordinates)
    : defeat_coordinates{coordinates}{}

std::string DefeatMessage::createMessage() const
{
    std::ostringstream buffer;
    buffer << "DEFEAT || COORDINATES: " << defeat_coordinates;
    return buffer.str();
}
