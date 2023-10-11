#ifndef PLAYERCONTOLLER_HH
#define PLAYERCONTOLLER_HH

#include "../Field/Field.hh"
#include "../Player/Player.hh"
#include "Coordinates.hh"

enum class Direction {UP, DOWN, LEFT, RIGHT};

class PlayerController
{
    Field &field;
    Player &player;
    Coordinates coordinates;

public:
    PlayerController(Field &field, Player &player);

    const Coordinates& getCoordinates();

    void move(Direction direction);
};

#endif
