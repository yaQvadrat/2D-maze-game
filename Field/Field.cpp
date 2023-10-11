#include "Field.hh"

bool Field::checkFieldSize(int width, int height)
{
    return width >= MIN_SIZE && width <= MAX_SIZE && height >= MIN_SIZE && height <= MAX_SIZE;
}

bool Field::checkCoordinates(Coordinates coord)
{
    int x = coord.getX();
    int y = coord.getY();
    return x >= 0 && x < width && y >= 0 && y < height; 
}

Field::Field(int width = DEF_SIZE, int height = DEF_SIZE): width{width}, height{height}
{
    if (!checkFieldSize(width, height))
        throw std::invalid_argument("Invalid field size");
    entry = {DEF_ENTRY, DEF_ENTRY};
    exit = {width - 1, height - 1};
    cells = new Cell*[width];
    for (size_t x = 0; x < width; ++x)
        cells[x] = new Cell[height];
}

Field::~Field()
{
    for (size_t x = 0; x < width; ++x)
        delete [] cells[x];
    delete [] cells;
}

const Cell& Field::getCell(Coordinates coord)
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

Coordinates Field::getEntry()
{
    return entry;
}

Coordinates Field::getExit()
{
    return exit;
}
