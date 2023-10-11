#include "Coordinates.hh"

Coordinates::Coordinates(int x, int y): x{x}, y{y}{}

int Coordinates::getX() const
{
    return x;
}

int Coordinates::getY() const
{
    return y;
}

bool Coordinates::operator==(const Coordinates &other) const
{
    return x == other.x && y == other.y;
}

bool Coordinates::operator!=(const Coordinates &other) const
{
    return x != other.x || y != other.y;
}
