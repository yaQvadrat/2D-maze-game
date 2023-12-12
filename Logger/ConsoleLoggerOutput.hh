#ifndef CONSOLE_LOGGER_OUTPUT_HH
#define CONSOLE_LOGGER_OUTPUT_HH

#include "ILoggerOutput.hh"
#include <sstream>

class ConsoleLoggerOutput: public ILoggerOutput
{
    std::ostringstream buffer;
public:
    void log(const std::string &logs) override;
};

#endif
