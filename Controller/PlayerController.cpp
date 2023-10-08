#include "PlayerController.hh"

PlayerController::PlayerController(Player &player, int x, int y): player{player}
{
    Coordinates coord(x, y);
    if (check(coord))
        coordinates = coord;
}

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
    if(!check(coordinates))
        coordinates = before_change;
}

bool PlayerController::check(Coordinates coord)
{
    return true;
}
