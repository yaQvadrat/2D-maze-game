#ifndef PLAYERCONTOLLER_HH
#define PLAYERCONTOLLER_HH

#include "../Player/Player.hh"
#include "Coordinates.hh"

enum class Direction {UP, DOWN, LEFT, RIGHT};

class PlayerController
{
    Player &player;
    Coordinates coordinates;

    bool check(Coordinates coord);

public:
    PlayerController(Player &player, int x = DEF_X, int y = DEF_Y);

    const Coordinates& getCoordinates();

    void move(Direction direction);
};

#endif
