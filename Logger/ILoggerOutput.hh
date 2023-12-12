#ifndef I_LOGGER_OUTPUT_HH
#define I_LOGGER_OUTPUT_HH

class AbstractLogMessage;

class ILoggerOutput
{
public:
    virtual ~ILoggerOutput(){}
    virtual void log(const AbstractLogMessage &msg) = 0;
};

#endif
