#include "Player.hh"
#include <iostream>

Characteristic& Player::get(Option opt) const
{
    return mapping.at(opt);
}

bool Player::isAlive()
{
    return health.getValue() != health.getMinValue();
}
