#include "TrapEvent.hh"
#include "../Player/Player.hh"
#include "../Controller/PlayerController.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

TrapEvent::TrapEvent(int damage)
    : damage{damage >= 0 ? damage : -damage}{}


void TrapEvent::triggerEvent(PlayerController &controller)
{
    Characteristic &health = controller.getPlayer().get(Option::HEALTH);
    health.setValue(health.getValue() - damage);
    Cell &cell = controller.getField().getCell(controller.getCoordinates());
    cell = Cell(cell.getPassable(), nullptr);
}

TrapEvent* TrapEvent::clone()
{
    return new TrapEvent(*this);
}

