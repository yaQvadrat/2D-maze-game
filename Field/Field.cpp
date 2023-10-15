#include "Field.hh"

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
    for (size_t x = 0; x < this->width; ++x)
        cells[x] = new Cell[this->height];
}

Field::~Field()
{
    for (size_t x = 0; x < width; ++x)
        delete [] cells[x];
    delete [] cells;
}

Field::Field(const Field &other)
    : width{other.width}, height{other.height},
      entry{other.entry}, exit{other.exit},
      cells{new Cell*[other.width]}
{
    for (size_t x = 0; x < width; ++x) {
        cells[x] = new Cell[height];
        for (size_t y = 0; y < height; ++y)
            cells[x][y] = other.cells[x][y];
    }
}

Field& Field::operator=(const Field &other)
{
    if (this != &other) {
        for (size_t x = 0; x < width; ++x)
            delete [] cells[x];
        delete [] cells;
        width = other.width;
        height = other.height;
        entry = other.entry;
        exit = other.exit;
        cells = new Cell*[width];
        for (size_t x = 0; x < width; ++x) {
            cells[x] = new Cell[height];
            for (size_t y = 0; y < height; ++y)
                cells[x][y] = other.cells[x][y];
        }
    }
    return *this;
}

Field::Field(Field &&other)
    : width{0}, height{0},
      entry{Coordinates()}, exit{Coordinates()},
      cells{nullptr} 
{
    std::swap(width, other.width);
    std::swap(height, other.width);
    std::swap(entry, other.entry);
    std::swap(exit, other.exit);
    std::swap(cells, other.cells);
}

Field& Field::operator=(Field &&other)
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

const Cell& Field::getCell(Coordinates coord) const
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

void Field::setPassable(Coordinates coordinates, bool passable)
{
    if (checkCoordinates(coordinates))
        cells[coordinates.getX()][coordinates.getY()].setPassable(passable);
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
