#ifndef PLAYER_CONTROLLER_HH
#define PLAYER_CONTROLLER_HH

#include <iostream>
#include "Player.hh"

enum class Direction {UP, DOWN, LEFT, RIGHT};

class PlayerController
{
    Player& player;
    std::pair<int, int> coordinates;

    bool valid_coord(std::pair<int, int> coord);

public:
    PlayerController(Player& cur_player, std::pair<int, int> coord = {0, 0});
   
    std::pair<int, int> get_both_coord();

    int get_x();

    int get_y();

    void set_both_coord(std::pair<int, int> coord);

    void set_x(int x);

    void set_y(int y);

    void change_coord(std::pair<int, int> offset);

    void move(Direction direction);
    
    void change_health(int value);

    void change_attempts(int value);

    void change_points(int value);
};

#endif
