#ifndef I_LOGGER_OUTPUT_HH
#define I_LOGGER_OUTPUT_HH

#include <string>

class AbstractLogMessage;

class ILoggerOutput
{
public:
    virtual ~ILoggerOutput(){}
    virtual void log(const std::string &logs) = 0;
};

#endif
