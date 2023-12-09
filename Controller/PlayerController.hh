#ifndef PLAYERCONTROLLER_HH
#define PLAYERCONTROLLER_HH

#include "Coordinates.hh"
#include "Direction.hh"
#include "../Characteristic/Option.hh"

class Field;
class Player;

class PlayerController
{
    Field &field;
    Player &player;
    Coordinates coordinates;

public:
    PlayerController(Field &field, Player &player);

    Coordinates getCoordinates() const;
    void setCoordinates(Coordinates coordinates);

    void change(Option opt, int offset);

    void move(Direction direction);

    const Player& getPlayer() const;
    const Field& getField() const;
};

#endif
