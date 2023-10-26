#include "PlayerController.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"
#include "../Event/IEvent.hh"

PlayerController::PlayerController(Field &field, Player &player)
    : field{field}, player{player}, coordinates{field.getEntry()}{}

Coordinates PlayerController::getCoordinates()
{
    return coordinates;
}

Player& PlayerController::getPlayer()
{
    return player;
}

Field& PlayerController::getField()
{
    return field;
}

void PlayerController::move(Direction direction)
{
    Coordinates before_change = coordinates;
    switch (direction)
    {
    case Direction::UP:
        coordinates.y += 1;
        break;
    
    case Direction::DOWN:
        coordinates.y -= 1;
        break;
    
    case Direction::LEFT:
        coordinates.x -= 1;
        break;
    
    case Direction::RIGHT:
        coordinates.x += 1;
        break;
    }
    if(!(field.checkCoordinates(coordinates) && field.getCell(coordinates).getPassable()))
        coordinates = before_change;

    IEvent* event = field.getCell(coordinates).getEvent();
    if (event)
        event->triggerEvent(*this);
}
