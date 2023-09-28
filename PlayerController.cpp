#include "PlayerController.hh"

bool PlayerController::valid_coord(std::pair<int, int> coord)
{
    return coord.first >= 0 && coord.second >= 0;
}

PlayerController::PlayerController(Player& cur_player, std::pair<int, int> coord): player{cur_player}
{
    if (coord.first < 0 || coord.second < 0)
        throw std::invalid_argument("Coordinates cannot be negative");
    coordinates = coord;
}

std::pair<int, int> PlayerController::get_both_coord()
{
    return coordinates;
}

int PlayerController::get_x()
{
    return coordinates.first;
}

int PlayerController::get_y()
{
    return coordinates.second;
}

void PlayerController::set_both_coord(std::pair<int, int> coord)
{
    if (valid_coord(coord))
        coordinates = coord;
}

void PlayerController::set_x(int x)
{
    if(valid_coord({x, coordinates.second}))
        coordinates.first = x;
}

void PlayerController::set_y(int y)
{
    if(valid_coord({coordinates.first, y}))
        coordinates.second = y;
}

void PlayerController::change_coord(std::pair<int, int> offset)
{
    if (valid_coord({coordinates.first + offset.first, coordinates.second + offset.second})) {
        coordinates.first += offset.first;
        coordinates.second += offset.second;
    }
}

void PlayerController::move(Direction direction)
{
    switch (direction)
    {
    case Direction::UP:
        change_coord({0, 1});
        break;
    
    case Direction::DOWN:
        change_coord({0, -1});
        break;
    case Direction::LEFT:
        change_coord({-1, 0});
        break;
    
    case Direction::RIGHT:
        change_coord({1, 0});
        break;
    }
}

void PlayerController::change_health(int value)
{
    player.set_health(player.get_health() + value);
}

void PlayerController::change_attempts(int value)
{
    player.set_attempts(player.get_attempts() + value);
}

void PlayerController::change_points(int value)
{
    player.set_points(player.get_points() + value);
}
