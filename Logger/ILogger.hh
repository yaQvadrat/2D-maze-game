#ifndef I_LOGGER_HH
#define I_LOGGER_HH

class AbstractLogMessage;

class ILogger
{
public:
    virtual ~ILogger(){}
    virtual void initLogger() = 0;
    virtual void logMessage(const AbstractLogMessage &msg) = 0;
};

#endif
