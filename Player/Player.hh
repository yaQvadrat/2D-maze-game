#ifndef PLAYER_HH
#define PLAYER_HH

#include "../Characteristic/Health.hh"
#include "../Characteristic/Points.hh"
#include "../Characteristic/Option.hh"
#include <map>
#define MAX_HEALTH 100
#define MIN_HEALTH 0
#define MAX_POINTS 1000
#define MIN_POINTS 0
#define DEF_HEALTH 100
#define DEF_POINTS 0

class Player
{
    Health health = Health(MIN_HEALTH, MAX_HEALTH, DEF_HEALTH);
    Points points = Points(MIN_POINTS, MAX_POINTS, DEF_POINTS);
    std::map<Option, Characteristic&> mapping = 
    {
        {Option::HEALTH, health}, {Option::POINTS, points}
    };

public:
    Characteristic& get(Option opt);

    bool isAlive();
};

#endif
