#include "ConsoleLoggerOutput.hh"
#include "AbstractLogMessage.hh"

void ConsoleLoggerOutput::log(const std::string &logs)
{
    std::cout << logs;
}
