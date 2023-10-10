#include "PointsEvent.hh"

void PointsEvent::triggerEvent()
{
    std::cout << "Some points related event\n";
}

PointsEvent* PointsEvent::clone()
{
    return new PointsEvent(*this);
}
