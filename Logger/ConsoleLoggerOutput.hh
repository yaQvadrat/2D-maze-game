#ifndef CONSOLE_LOGGER_OUTPUT_HH
#define CONSOLE_LOGGER_OUTPUT_HH

#include "ILoggerOutput.hh"

class ConsoleLoggerOutput: public ILoggerOutput
{
public:
    void log(const AbstractLogMessage &msg) override;
};

#endif
