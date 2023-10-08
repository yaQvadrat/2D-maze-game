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
