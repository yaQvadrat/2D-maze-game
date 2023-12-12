#include "WinMessage.hh"
#include <sstream>

WinMessage::WinMessage(int health, int points): health{health}, points{points}
{}

std::string WinMessage::createMessage() const
{
    std::ostringstream buffer;
    buffer << "VICTORY || HP: " << health << " || POINTS: " << points;
    return buffer.str();
}
