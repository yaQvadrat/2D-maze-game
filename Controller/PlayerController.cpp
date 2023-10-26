#include "PlayerController.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"
#include "../Event/IEvent.hh"
#include "../Player/Player.hh"

PlayerController::PlayerController(Field &field, Player &player)
    : field{field}, player{player}, coordinates{field.getEntry()}{}

Coordinates PlayerController::getCoordinates()
{
    return coordinates;
}

void PlayerController::change(Option opt, int offset)
{
    player.get(opt).setValue(player.get(opt).getValue() + offset);
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

    field.getCell(coordinates).triggerEvent(*this);
}
