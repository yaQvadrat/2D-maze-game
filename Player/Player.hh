#ifndef PLAYER_HH
#define PLAYER_HH

#include "../Characteristic/Health.hh"
#include "../Characteristic/Points.hh"
#include "../Characteristic/Option.hh"
#include <map>
constexpr int MAX_HEALTH = 100;
constexpr int MIN_HEALTH = 0;
constexpr int MAX_POINTS = 5000;
constexpr int MIN_POINTS = 0;
constexpr int DEF_HEALTH = 100;
constexpr int DEF_POINTS = 0;

class Player
{
    Health health = Health(MIN_HEALTH, MAX_HEALTH, DEF_HEALTH);
    Points points = Points(MIN_POINTS, MAX_POINTS, DEF_POINTS);
    std::map<Option, Characteristic&> mapping = 
    {
        {Option::HEALTH, health}, {Option::POINTS, points}
    };

public:
    Characteristic& get(Option opt) const;

    bool isAlive();
};

#endif
