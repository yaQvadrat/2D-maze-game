#include "Player.hh"
#include <iostream>

Characteristic& Player::get(Option opt)
{
    return mapping.at(opt);
}

bool Player::isAlive()
{
    return health.getValue() != health.getMinValue();
}
