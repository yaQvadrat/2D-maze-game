#ifndef PLAYERCONTROLLER_HH
#define PLAYERCONTROLLER_HH

#include "Coordinates.hh"
#include "Direction.hh"

class Field;
class Player;

class PlayerController
{
    Field &field;
    Player &player;
    Coordinates coordinates;

public:
    PlayerController(Field &field, Player &player);

    Coordinates getCoordinates();
    Player& getPlayer();
    Field& getField();

    void move(Direction direction);
};

#endif
