#include "PlayerController.hh"

PlayerController::PlayerController(Field &field, Player &player)
    : field{field}, player{player}, coordinates{field.getEntry()}{}

const Coordinates& PlayerController::getCoordinates()
{
    return coordinates;
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
}
