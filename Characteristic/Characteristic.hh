#ifndef CHARACTERISTIC_HH
#define CHARACTERISTIC_HH

#define GREATER 1
#define LOWER -1
#define NORMAL 0

class Characteristic
{
    int min_value;
    int max_value;
    int value;

    int check(int value);

public:
    Characteristic(int min_value, int max_value, int value);

    void setValue(int value);
    void setMinValue(int value);
    void setMaxValue(int value);

    int getValue() const;
    int getMinValue();
    int getMaxValue();
};

#endif
