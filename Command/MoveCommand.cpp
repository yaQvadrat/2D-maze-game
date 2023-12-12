#include "MoveCommand.hh"
#include "../Game/Game.hh"

MoveCommand::MoveCommand(Direction direction): direction{direction}{}

void MoveCommand::execute(Game &game) 
{
    game.movePlayer(direction);
}

Direction MoveCommand::getDirection()
{
    return direction;
}