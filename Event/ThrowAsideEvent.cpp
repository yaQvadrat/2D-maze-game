#include "ThrowAsideEvent.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

ThrowAsideEvent::ThrowAsideEvent(Direction direction)
    : direction{direction}{}

void ThrowAsideEvent::triggerEvent(PlayerController &controller)
{
    if (use_count != 0) {
        Cell &cell = controller.getField().getCell(controller.getCoordinates());
        cell = Cell(cell.getPassable(), nullptr);
    }
    use_count++;
    controller.move(direction);
}

ThrowAsideEvent* ThrowAsideEvent::clone()
{
    return new ThrowAsideEvent(*this);
}