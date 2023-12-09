#include "Game.hh"
#include "../Player/Player.hh"
#include "../Observer/IObserver.hh"

Game::Game()
    : controller{field, player}, 
      state{GameState::MENU}{}

void Game::attachObserver(IObserver *observer)
{
    observer_list.push_back(observer);
}

void Game::detachObserver(IObserver *observer)
{
    observer_list.remove(observer);
}

void Game::notify()
{
    for (auto observer: observer_list)
        observer->update();
}

void Game::setLevel(int level)
{
    field = *(field_creator.getLevel(level));
    controller.setCoordinates(field.getEntry());
    player.get(Option::HEALTH).setMaxValue();
    player.get(Option::POINTS).setMinValue();
    notify();
}

void Game::movePlayer(Direction direction)
{
    controller.move(direction);
    if (!player.isAlive()) {
        setState(GameState::DEFEAT);
    } else if (controller.getCoordinates() == field.getExit()) {
        setState(GameState::VICTORY);
    } else {
        notify();
    }
}

void Game::setState(GameState new_state)
{
    state = new_state;
    notify();
}

GameState Game::getState()
{
    return state;
}

const PlayerController& Game::getController()
{
    return controller;
}
