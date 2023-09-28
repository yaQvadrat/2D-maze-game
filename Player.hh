#ifndef PLAYER_HH
#define PLAYER_HH

#include <iostream>

class Player
{
    int health;
    int attempts = 1;
    int points = 0;

    bool is_valid(int value);

public:
    Player(int health = 100);

    Player(int health, int attempts);

    Player (int health, int attempts, int points);

    int get_health();

    int get_attempts();

    int get_points();

    void set_health(int value);
   
    void set_attempts(int value);

    void set_points(int value);
};

#endif
