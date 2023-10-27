#ifndef THROW_ASIDE_EVENT_HH
#define THROW_ASIDE_EVENT_HH

#include "IEvent.hh"
#include "../Controller/PlayerController.hh"
#include <iostream>

class ThrowAsideEvent: public IEvent
{
    size_t use_count = 0;
    Direction direction;

public:
    ThrowAsideEvent(Direction direction);

    void trigger(PlayerController &controller) override;

    ThrowAsideEvent* clone() override;
};

#endif
