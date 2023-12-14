#ifndef GAME_VIEW_OBSERVER_HH
#define GAME_VIEW_OBSERVER_HH

#include "../Observer/IObserver.hh"
#include "Game.hh"
#include "IGameView.hh"
#include <map>
#include <functional>

class GameViewObserver: IObserver
{
    IGameView &displayer;
    Game &game;
    std::map<GameState, std::function<void()>> display_map = 
    {
        {GameState::IN_PROGRESS, [this](){displayer.displayGame(game.getController());}},
        {GameState::MENU, [this](){displayer.displayMenu();}},
        {GameState::VICTORY, [this](){displayer.displayGame(game.getController()); displayer.displayWinMenu();}},
        {GameState::DEFEAT, [this](){displayer.displayGame(game.getController()); displayer.displayDefeatMenu();}},
        {GameState::RESTART, [this](){displayer.displayGame(game.getController()); displayer.displayRestartMenu();}}
    };
public:
    GameViewObserver(IGameView &displayer, Game &game);

    void update() override;
};

#endif
