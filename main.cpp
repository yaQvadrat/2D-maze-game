#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include "Field/Cell.hh"
#include "Event/PointsEvent.hh"
#include <iostream>
#include <memory>


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
    Cell **cell_arr;

    bool checkFieldSize(int width, int height)
    {
        return width >= MIN_SIZE && width <= MAX_SIZE && height >= MIN_SIZE && height <= MAX_SIZE;
    }

    bool checkCoordinates(Coordinates coord)
    {
        int x = coord.getX();
        int y = coord.getY();
        return x >= 0 && x <= width && y >= 0 && y <= height; 
    }

public:
    Field(int width = DEF_SIZE, int height = DEF_SIZE): width{width}, height{height}
    {
        if (!checkFieldSize(width, height))
            throw std::invalid_argument("Invalid field size");
        entry = {DEF_ENTRY, DEF_ENTRY};
        exit = {width - 1, height - 1};
        cell_arr = new Cell*[height];
        for (size_t y = 0; y < height; ++y)
        {
            cell_arr[y] = new Cell[width];
        }
    }

    ~Field()
    {
        for (size_t y = 0; y < height; ++y)
        {
            delete[] cell_arr[y];
        }
        delete[] cell_arr;
    }

    const Cell& getCell(Coordinates coord)
    {
        if (!checkCoordinates(coord))
            throw std::out_of_range("Invalid cell coordinates");
        return cell_arr[coord.getY()][coord.getX()];
    }

    void setEntry(Coordinates entry)
    {
        if(checkCoordinates(entry) && (entry != exit))
            this->entry = entry;
    }

    void setExit(Coordinates exit)
    {
        if(checkCoordinates(entry) && (entry != exit))
            this->exit = exit;
    }

};


int main()
{
    // LAB1
    Player my_player;
    std::cout << my_player.getValue(Option::HEALTH) << ": HP| " << my_player.getValue(Option::POINTS) << ": POINTS|\n";
    my_player.setValue(Option::HEALTH, 90);
    my_player.getValue(Option::HEALTH);
    std::cout << my_player.getValue(Option::HEALTH) << ": HP|\n";
    PlayerController controller(my_player);
    Coordinates coord = controller.getCoordinates();
    std::cout << coord.getX() << ": X| " << coord.getY() << ": Y|\n";
    my_player.setValue(Option::POINTS, 500000);
    std::cout << my_player.getValue(Option::POINTS) << ": POINTS|\n";

    // LAB2
    IEvent *event = new PointsEvent;
    Cell cell(false, event);
    std::cout << cell.getPassable() << "\n";
    cell.setPassable();
    std::cout << cell.getPassable() << "\n";
    Cell new_cell = cell;
    Field field(15, 15);
    Cell cl = field.getCell({5, 6});
    std::cout << cl.getPassable() << "\n";
    return 0;
}
