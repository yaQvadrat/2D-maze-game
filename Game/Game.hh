#ifndef GAME_HH
#define GAME_HH

#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/FieldCreator.hh"
#include "../Observer/ISubject.hh"
#include <list>

class IObserver;

enum class GameState {IN_PROGRESS, VICTORY, DEFEAT, QUIT, MENU, RESTART};

class Game: ISubject
{
    Player player;
    Field field;
    PlayerController controller;
    FieldCreator field_creator;
    GameState state;
    std::list<IObserver*> observer_list;

public:
    Game();

    void attachObserver(IObserver *observer) override;
    void detachObserver(IObserver *observer) override;
    void notify() override;

    void setLevel(int level);
    
    void movePlayer(Direction direction);

    void setState(GameState new_state);
    GameState getState();

    const PlayerController& getController();
};

#endif
