#include "ThrowAsideEvent.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"

ThrowAsideEvent::ThrowAsideEvent(Direction direction)
    : direction{direction}{}

void ThrowAsideEvent::trigger(PlayerController &controller)
{
    if (use_count == 0) {
        use_count++;
        controller.move(direction);
    }
}

ThrowAsideEvent* ThrowAsideEvent::clone()
{
    return new ThrowAsideEvent(*this);
}

Direction ThrowAsideEvent::getDirection() const
{
    return direction;
}
