#include "Cell.hh"
#include <iostream>

Cell::Cell(bool passable, IEvent *event)
    : passable{passable}, event{event}{}

Cell::~Cell()
{
    delete event;
}

Cell::Cell(const Cell &other)
    : passable{other.passable},
      event{other.event ? other.event->clone() : nullptr}{}

Cell& Cell::operator=(const Cell &other)
{
    if (this != &other) {
        Cell temp(other);
        std::swap(passable, temp.passable);
        std::swap(event, temp.event);
    }
    return *this;
}

Cell::Cell(Cell &&other)
    :passable{true}, event{nullptr}
{
    std::swap(passable, other.passable);
    std::swap(event, other.event);
}

Cell& Cell::operator=(Cell &&other)
{
    if (this != &other) {
        std::swap(passable, other.passable);
        std::swap(event, other.event);
    }
    return *this;
}

void Cell::setPassable(bool passable)
{
    this->passable = passable;
}

bool Cell::getPassable() const
{
    return passable;
}
