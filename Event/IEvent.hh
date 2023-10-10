#ifndef IEVENT_HH
#define IEVENT_HH

class IEvent
{
public:
    virtual void triggerEvent() = 0;
    virtual IEvent* clone() = 0;
};

#endif
