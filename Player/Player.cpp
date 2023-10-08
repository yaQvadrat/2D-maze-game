#include "Player.hh"

int Player::getValue(Option opt)
{
    return mapping.at(opt).getValue();
}

void Player::setValue(Option opt, int value)
{
    mapping.at(opt).setValue(value);
}

