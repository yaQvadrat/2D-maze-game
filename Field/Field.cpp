#include "Field.hh"
#include "Cell.hh"
#include <iostream>

bool Field::checkFieldSize(int width, int height)
{
    return width >= MIN_SIZE && width <= MAX_SIZE && height >= MIN_SIZE && height <= MAX_SIZE;
}

bool Field::checkCoordinates(Coordinates coord) const
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < width && y >= 0 && y < height; 
}

Field::Field(int width, int height): width{width}, height{height}
{
    if (!checkFieldSize(width, height))
        this->width = this->height = DEF_SIZE;
    entry = {DEF_ENTRY, DEF_ENTRY};
    exit = {this->width - 1, this->height - 1};
    cells = new Cell*[this->width];
    for (int x = 0; x < this->width; ++x)
        cells[x] = new Cell[this->height];
}

Field::~Field()
{
    for (int x = 0; x < width; ++x)
        delete [] cells[x];
    delete [] cells;
}

Field::Field(const Field &other)
    : width{other.width}, height{other.height},
      entry{other.entry}, exit{other.exit},
      cells{new Cell*[other.width]}
{
    for (int x = 0; x < width; ++x) {
        cells[x] = new Cell[height];
        for (int y = 0; y < height; ++y)
            cells[x][y] = other.cells[x][y];
    }
}

Field& Field::operator = (const Field &other)
{
    if (this != &other) {
        for (int x = 0; x < width; ++x)
            delete [] cells[x];
        delete [] cells;
        width = other.width;
        height = other.height;
        entry = other.entry;
        exit = other.exit;
        cells = new Cell*[width];
        for (int x = 0; x < width; ++x) {
            cells[x] = new Cell[height];
            for (int y = 0; y < height; ++y)
                cells[x][y] = other.cells[x][y];
        }
    }
    return *this;
}

Field::Field(Field &&other)
    : width{std::move(other.width)}, height{},
      entry{Coordinates()}, exit{Coordinates()},
      cells{nullptr} 
{
    *this = std::move(other);
}

Field& Field::operator = (Field &&other)
{
    if (this != &other) {
        std::swap(width, other.width);
        std::swap(height, other.width);
        std::swap(entry, other.entry);
        std::swap(exit, other.exit);
        std::swap(cells, other.cells);
    }
    return *this;
}

Cell& Field::getCell(Coordinates coord) const
{
    if (!checkCoordinates(coord))
        throw std::out_of_range("Invalid cell coordinates");
    return cells[coord.getX()][coord.getY()];
}

void Field::setEntry(Coordinates entry)
{
    if(checkCoordinates(entry) && (entry != exit))
        this->entry = entry;
}

void Field::setExit(Coordinates exit)
{
    if(checkCoordinates(exit) && (entry != exit))
        this->exit = exit;
}

void Field::setPassableBlock(bool passable, Coordinates dwn_lft, Coordinates up_rght)
{
    if (!(checkCoordinates(dwn_lft) && checkCoordinates(up_rght)))
        return;
    if (!(dwn_lft.getX() <= up_rght.getX() && dwn_lft.getY() <= up_rght.getY()))
        return;
    for (int x = dwn_lft.getX(); x <= up_rght.getX(); ++x) {
        for (int y = dwn_lft.getY(); y <= up_rght.getY(); ++y)
            getCell({x, y}).setPassable(passable);
    }
}

Coordinates Field::getEntry()
{
    return entry;
}

Coordinates Field::getExit()
{
    return exit;
}

int Field::getWidth()
{
    return width;
}

int Field::getHeight()
{
    return height;
}
