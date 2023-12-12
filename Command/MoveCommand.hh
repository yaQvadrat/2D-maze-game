#ifndef MOVE_COMMAND_HH
#define MOVE_COMMAND_HH

#include "ICommand.hh"
#include "../Controller/Direction.hh"

class MoveCommand: public ICommand
{
    Direction direction;
public:
    MoveCommand(Direction direction);
    Direction getDirection();

    void execute(Game &game) override;
};

#endif
