#include "ExitCommand.hh"
#include "../Game/Game.hh"

void ExitCommand::execute(Game &game) 
{
    game.setState(GameState::QUIT);
}