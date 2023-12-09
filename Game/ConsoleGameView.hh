#ifndef CONSOLE_GAME_VIEW_HH
#define CONSOLE_GAME_VIEW_HH

#include "IGameView.hh"
#include "../Controller/Coordinates.hh"
#include <map>

class PlayerController;
class Field;

enum class Object
{
    WALL,
    CELL,
    START,
    EXIT,
    PLAYER,
    THROW_UP,
    THROW_DOWN,
    THROW_LEFT,
    THROW_RIGHT,
    POINTS_EVENT,
    TRAP_EVENT
};

class ConsoleGameView: public IGameView
{
    std::map<Object, std::string> object_view
    {
        {Object::CELL, "[ ]"}, {Object::WALL, "\033[33m[#]\033[0m"},
        {Object::START, "[S]"}, {Object::EXIT, "[E]"},
        {Object::PLAYER, "\033[35m[@]\033[0m"}, {Object::POINTS_EVENT, "\033[32m[P]\033[0m"},
        {Object::TRAP_EVENT, "\033[31m[T]\033[0m"}, {Object::THROW_UP, "[^]"},
        {Object::THROW_DOWN, "[v]"}, {Object::THROW_LEFT, "[<]"},
        {Object::THROW_RIGHT, "[>]"}
    };

    Object getObject(Coordinates cell_coord, Coordinates player_coord, const Field &field);

public:
    void displayGame(const PlayerController &controller) override;
    void displayMenu() override;
    void displayWinMenu() override;
    void displayDefeatMenu() override;
    void displayRestartMenu() override;
    void initView() override;
};

#endif
