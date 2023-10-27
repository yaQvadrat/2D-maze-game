#ifndef TRAP_EVENT_HH
#define TRAP_EVENT_HH

#include "IEvent.hh"

#define DEF_DAMAGE_IN_TRAP_EVENT 10

class TrapEvent: public IEvent
{
    int damage;

public:
    TrapEvent(int damage = DEF_DAMAGE_IN_TRAP_EVENT);

    void trigger(PlayerController &controller) override;

    TrapEvent* clone() override;
};

#endif
