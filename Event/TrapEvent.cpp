#include "TrapEvent.hh"
#include "../Player/Player.hh"
#include "../Controller/PlayerController.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

TrapEvent::TrapEvent(int damage)
    : damage{damage >= 0 ? damage : -damage}{}


void TrapEvent::triggerEvent(PlayerController &controller)
{
    controller.change(Option::HEALTH, -damage);
}

TrapEvent* TrapEvent::clone()
{
    return new TrapEvent(*this);
}

