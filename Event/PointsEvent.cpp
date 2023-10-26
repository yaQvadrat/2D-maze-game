#include "PointsEvent.hh"
#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

PointsEvent::PointsEvent(int points_offset): points_offset{points_offset}{}

void PointsEvent::triggerEvent(PlayerController &controller)
{
    controller.change(Option::POINTS, points_offset);
}

PointsEvent* PointsEvent::clone()
{
    return new PointsEvent(*this);
}
