#include "Characteristic.hh"
#include <iostream>

Characteristic::Characteristic(int min_value, int max_value, int value) 
{
    if (min_value >= max_value)
        throw std::invalid_argument("The minimum value must be less than the maximum");
    this->min_value = min_value;
    this->max_value = max_value;
    setValue(value);
}

void Characteristic::setValue(int value)
{
    int status = check(value);
    if (status == GREATER)
        this->value = max_value;
    else if (status == LOWER)
        this->value = min_value;
    else
        this->value = value;
}

int Characteristic::getValue() const
{
    return value;
}

int Characteristic::check(int value)
{
    if (value > max_value)
        return GREATER;
    else if (value < min_value)
        return LOWER;
    return NORMAL;
}
