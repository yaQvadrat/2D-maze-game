#ifndef FIELD_HH
#define FIELD_HH

#include "../Controller/Coordinates.hh"
#include "Cell.hh"
#include <iostream>

#define MAX_SIZE 20
#define MIN_SIZE 2
#define DEF_SIZE 10
#define DEF_ENTRY 0

class Field
{
    int width;
    int height;
    Coordinates entry;
    Coordinates exit;
    Cell **cells;

    bool checkFieldSize(int width, int height);

    bool checkCoordinates(Coordinates coord);

public:
    Field(int width = DEF_SIZE, int height = DEF_SIZE): width{width}, height{height}
    {
        if (!checkFieldSize(width, height))
            throw std::invalid_argument("Invalid field size");
        entry = {DEF_ENTRY, DEF_ENTRY};
        exit = {width - 1, height - 1};
        cells = new Cell*[width];
        for (size_t x = 0; x < width; ++x)
            cells[x] = new Cell[height];
    }

    ~Field()
    {
        for (size_t x = 0; x < width; ++x)
            delete [] cells[x];
        delete [] cells;
    }

    const Cell& getCell(Coordinates coord)
    {
        if (!checkCoordinates(coord))
            throw std::out_of_range("Invalid cell coordinates");
        return cells[coord.getX()][coord.getY()];
    }

    void setEntry(Coordinates entry)
    {
        if(checkCoordinates(entry) && (entry != exit))
            this->entry = entry;
    }

    void setExit(Coordinates exit)
    {
        if(checkCoordinates(exit) && (entry != exit))
            this->exit = exit;
    }

    Coordinates getEntry()
    {
        return entry;
    }

    Coordinates getExit()
    {
        return exit;
    }
};

#endif
