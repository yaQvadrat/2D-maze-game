#include "RestartCommand.hh"
#include "../Game/Game.hh"

void RestartCommand::execute(Game &game)
{
    game.setState(GameState::MENU);
}
