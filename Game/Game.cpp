#include "Game.hh"
#include "../Player/Player.hh"
#include "../Observer/IObserver.hh"
#include "../Logger/ILogger.hh"
#include "../Logger/DefeatMessage.hh"
#include "../Logger/NewGameMessage.hh"
#include "../Logger/WinMessage.hh"

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
    sendLogMessage(NewGameMessage(field.getWidth(), field.getHeight(), field.getEntry()));
}

void Game::movePlayer(Direction direction)
{
    controller.move(direction);
    if (!player.isAlive()) {
        sendLogMessage(DefeatMessage(controller.getCoordinates()));
        setState(GameState::DEFEAT);
    } else if (controller.getCoordinates() == field.getExit()) {
        sendLogMessage(WinMessage(player.get(Option::HEALTH).getValue(), player.get(Option::POINTS).getValue()));
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

void Game::attachLogger(ILogger *logger)
{
    logger_list.push_back(logger);
}

void Game::detachLogger(ILogger *logger)
{
    logger_list.remove(logger);
}

void Game::sendLogMessage(const AbstractLogMessage &msg)
{
    for (auto logger: logger_list)
        logger->logMessage(msg);
}
