#ifndef I_GAME_VIEW_HH
#define I_GAME_VIEW_HH

class PlayerController;
class Player;
class Field;

class IGameView
{
public:
    virtual void displayGame(const PlayerController &controller) = 0;
    virtual void displayMenu() = 0;
    virtual void displayWinMenu() = 0;
    virtual void displayDefeatMenu() = 0;
    virtual void displayRestartMenu() = 0;
    virtual void initView() = 0;
};

#endif
