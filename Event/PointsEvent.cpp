#include "PointsEvent.hh"
#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

PointsEvent::PointsEvent(int points_offset): points_offset{points_offset}{}

void PointsEvent::triggerEvent(PlayerController &controller)
{
    Characteristic &points = controller.getPlayer().get(Option::POINTS);
    points.setValue(points.getValue() + points_offset);
    Cell &cell = controller.getField().getCell(controller.getCoordinates());
    cell = Cell(cell.getPassable(), nullptr);
}

PointsEvent* PointsEvent::clone()
{
    return new PointsEvent(*this);
}
