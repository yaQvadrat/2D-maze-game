#include "Player.hh"

bool Player::is_valid(int value)
{
    return value >= 0;
}

Player::Player(int health)
{
    if (health <= 0)
        throw std::invalid_argument("The player's health cannot be zero or less");
    this->health = health;
}

Player::Player(int health, int attempts) : Player(health)
{
    if (attempts <= 0)
        throw std::invalid_argument("The number of attempts cannot be zero or less");
    this->attempts = attempts;
}

Player::Player (int health, int attempts, int points): Player(health, attempts)
{
    if (points < 0)
        throw std::invalid_argument("The number of points cannot be less than zero");
    this->points = points;
}

int Player::get_health()
{
    return health;
}

int Player::get_attempts()
{
    return attempts;
}

int Player::get_points()
{
    return points;
}

void Player::set_health(int value)
{
    if (is_valid(value))
        health = value;
    else
        health = 0;
}

void Player::set_attempts(int value)
{
    if (is_valid(value))
        attempts = value;
    else
        attempts = 0;
}

void Player::set_points(int value)
{
    if (is_valid(value))
        points = value;
    else
        points = 0;
}
