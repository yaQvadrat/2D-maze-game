#ifndef GAME_HH
#define GAME_HH

#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/FieldCreator.hh"
#include "../Observer/ISubject.hh"
#include "../Logger/ILoggable.hh"
#include <list>

class IObserver;
class ILogger;

enum class GameState {IN_PROGRESS, VICTORY, DEFEAT, QUIT, MENU, RESTART};

class Game: ISubject, ILoggable
{
    Player player;
    Field field;
    PlayerController controller;
    FieldCreator field_creator;
    GameState state;
    std::list<IObserver*> observer_list;
    std::list<ILogger*> logger_list;

public:
    Game();

    void setLevel(int level);
    void movePlayer(Direction direction);

    void setState(GameState new_state);
    GameState getState();
    const PlayerController& getController();

    void attachObserver(IObserver *observer) override;
    void detachObserver(IObserver *observer) override;
    void notify() override;

    void attachLogger(ILogger *logger) override;
    void detachLogger(ILogger *logger) override;
    void sendLogMessage(const AbstractLogMessage &msg) override;
};

#endif
