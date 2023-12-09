#include "GameViewObserver.hh"

GameViewObserver::GameViewObserver(IGameView &displayer, Game &game)
    : displayer{displayer}, game{game}
{
    game.attachObserver(this);
    displayer.initView();
}

void GameViewObserver::update()
{
    GameState state = game.getState();
    if (display_map.contains(state))
        display_map.at(game.getState())();
}
