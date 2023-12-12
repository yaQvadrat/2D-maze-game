#include "ConsoleLoggerOutput.hh"
#include "AbstractLogMessage.hh"

void ConsoleLoggerOutput::log(const AbstractLogMessage &msg)
{
    std::cout << "\r" << msg;
}