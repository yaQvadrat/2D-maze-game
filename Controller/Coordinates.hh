#ifndef COORDINATES_HH
#define COORDINATES_hh

#define DEF_X 0
#define DEF_Y 0
class PlayerController;

class Coordinates
{
    friend PlayerController;
    int x;
    int y;

public:
    Coordinates(int x = DEF_X, int y = DEF_Y);

    int getX() const;

    int getY() const;
};

#endif
