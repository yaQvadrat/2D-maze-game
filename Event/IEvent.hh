#ifndef IEVENT_HH
#define IEVENT_HH

class PlayerController;

class IEvent
{
public:
    virtual ~IEvent() = 0;
    virtual void trigger(PlayerController &controller) = 0;
    virtual IEvent* clone() = 0;
};

#endif
