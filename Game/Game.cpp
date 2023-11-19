#include "Game.hh"
#include "../Player/Player.hh"

Game::Game()
    : controller{field, player}, 
      state{GameState::MENU}{}

void Game::setLevel(int level)
{
    field = *(field_creator.getLevel(level));
    controller.setCoordinates(field.getEntry());
    player.get(Option::HEALTH).setMaxValue();
    player.get(Option::POINTS).setMinValue();
}

void Game::movePlayer(Direction direction)
{
    controller.move(direction);
    std::cout << controller.getCoordinates() << " HP:";
    std::cout << player.get(Option::HEALTH).getValue() << " POINTS:";
    std::cout << player.get(Option::POINTS).getValue() << "\n";
    if (!player.isAlive()) {
        state = GameState::DEFEAT;
    } else if (controller.getCoordinates() == field.getExit()) {
        state = GameState::VICTORY;
    }
}

void Game::setState(GameState new_state)
{
    state = new_state;
}

GameState Game::getState()
{
    return state;
}
