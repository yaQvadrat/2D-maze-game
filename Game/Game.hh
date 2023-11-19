#ifndef GAME_HH
#define GAME_HH

#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/FieldCreator.hh"

enum class GameState {IN_PROGRESS, VICTORY, DEFEAT, QUIT, MENU};
class Game
{
    Player player;
    Field field;
    PlayerController controller;
    FieldCreator field_creator;
    GameState state;

public:
    Game();

    void setLevel(int level);
    
    void movePlayer(Direction direction);

    void setState(GameState new_state);
    GameState getState();
};

#endif
