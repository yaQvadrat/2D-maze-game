#ifndef I_LOGGABLE_HH
#define I_LOGGABLE_HH

class AbstractLogMessage;
class ILogger;

class ILoggable
{
public:
    virtual ~ILoggable(){}
    virtual void attachLogger(ILogger *logger) = 0;
    virtual void detachLogger(ILogger *logger) = 0;
    virtual void sendLogMessage(const AbstractLogMessage &msg) = 0;
};

#endif
