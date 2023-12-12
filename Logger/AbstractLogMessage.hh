#ifndef ABSTRACT_LOG_MESSAGE_HH
#define ABSTRACT_LOG_MESSAGE_HH

#include <iostream>

class AbstractLogMessage
{
public:
    virtual ~AbstractLogMessage(){};
    virtual std::string createMessage() const = 0;

    friend std::ostream& operator<<(std::ostream &os, const AbstractLogMessage &msg);
};

#endif
