#ifndef POINTS_EVENT_HH
#define POINTS_EVENT_HH

#include "IEvent.hh"
#include <iostream>

class PointsEvent: public IEvent
{
    void triggerEvent() override;

    PointsEvent* clone() override;
};

#endif
