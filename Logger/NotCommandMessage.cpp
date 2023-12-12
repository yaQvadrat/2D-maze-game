#include "NotCommandMessage.hh"
#include <sstream>

NotCommandMessage::NotCommandMessage(char key): key{key}{}

std::string NotCommandMessage::createMessage() const
{
    std::ostringstream buffer;
    buffer << "KEY PRESSED: " << key << " || NO ACTION";
    return buffer.str();
}
