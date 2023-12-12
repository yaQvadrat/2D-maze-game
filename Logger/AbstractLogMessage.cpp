#include "AbstractLogMessage.hh"

std::ostream& operator<<(std::ostream &os, const AbstractLogMessage &msg)
{
    return os << msg.createMessage();
}
