#ifndef FIELD_HH
#define FIELD_HH

#include "../Controller/Coordinates.hh"

#define MAX_SIZE 20
#define MIN_SIZE 2
#define DEF_SIZE 10
#define DEF_ENTRY 0

class Cell;

class Field
{
    int width;
    int height;
    Coordinates entry;
    Coordinates exit;
    Cell **cells;

    bool checkFieldSize(int width, int height);

public:
    Field(int width = DEF_SIZE, int height = DEF_SIZE);
    ~Field();

    Field(const Field &other);
    Field& operator = (const Field &other);
    Field(Field &&other);
    Field& operator = (Field &&other);
;

    void setEntry(Coordinates entry);
    void setExit(Coordinates exit);
    void setPassableBlock(bool passable, Coordinates dwn_lft, Coordinates up_rght);

    Cell& getCell(Coordinates coord) const;
    Coordinates getEntry();
    Coordinates getExit();
    int getWidth();
    int getHeight();

    bool checkCoordinates(Coordinates coord) const;
};

#endif
