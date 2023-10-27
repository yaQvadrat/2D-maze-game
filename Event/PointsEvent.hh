#ifndef POINTS_EVENT_HH
#define POINTS_EVENT_HH

#include "IEvent.hh"

#define DEF_POINTS_OFFSET 10

class PointsEvent: public IEvent
{
    int points_offset;

public:
    PointsEvent(int points_offset = DEF_POINTS_OFFSET);

    void trigger(PlayerController &controller) override;

    PointsEvent* clone() override;
};

#endif
