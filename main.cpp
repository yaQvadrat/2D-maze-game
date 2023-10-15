#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include "Field/Cell.hh"
#include "Field/Field.hh"
#include "Event/PointsEvent.hh"
#include <iostream>


int main()
{
    // LAB2
    // Cell test

    {
        IEvent *event = new PointsEvent;
        Cell cell(false, event);
        std::cout << std::boolalpha << cell.getPassable() << "\n";
        cell.setPassable();
        std::cout << std::boolalpha << cell.getPassable() << "\n\n\n";
        Cell new_cell1(cell);
        Cell new_cell2(Cell(false, new PointsEvent));
    }
    // Field + Player + Controller test
    {
        Player player;
        Field field;
        PlayerController controller(field, player);
        Coordinates coord = controller.getCoordinates();
        std::cout << field.getWidth() << "|" << field.getHeight() << " WIDTH|HEIGHT\n";
        std::cout << coord.getX() << " " << coord.getY() << " BEFORE MOVING\n";
        controller.move(Direction::LEFT);
        controller.move(Direction::DOWN);
        coord = controller.getCoordinates();
        std::cout << coord.getX() << " " << coord.getY() << " AFTER INVALID MOVING\n";
        controller.move(Direction::RIGHT);
        controller.move(Direction::UP);
        coord = controller.getCoordinates();
        std::cout << coord.getX() << " " << coord.getY() << " AFTER CORRECT MOVING\n\n\n";
    }
    {
        Player player;
        Field field(5, 5);
        std::cout << field.getWidth() << "|" << field.getHeight() << " WIDTH|HEIGHT\n";
        field.setEntry({0, 4});
        field.setExit({4, 0});
        field.setPassable({1, 4}, false);
        PlayerController controller(field, player);
        Coordinates coord = controller.getCoordinates();
        std::cout << coord.getX() << " " << coord.getY() << " BEFORE MOVING\n";
        controller.move(Direction::RIGHT);
        controller.move(Direction::UP);
        coord = controller.getCoordinates();
        std::cout << coord.getX() << " " << coord.getY() << " AFTER INVALID MOVING\n";
        controller.move(Direction::DOWN);
        coord = controller.getCoordinates();
        std::cout << coord.getX() << " " << coord.getY() << "\n";
        coord = field.getExit();
        std::cout << coord.getX() << " " << coord.getY() << " EXIT\n\n\n";
    }
    // Exception test
    try
    {
        Field field(1, 2);
    }
    catch(const std::invalid_argument& ex)
    {
        std::cout << ex.what() << '\n';
    }
    
    try
    {
        Field field(7, 8);
        field.getCell({10, 10});
    }
    catch(const std::out_of_range& ex)
    {
        std::cout << ex.what() << '\n';
    }

    {
        Field field1;
        field1.setPassable({5, 5}, false);
        Field field2(17, 17);
        field2.setEntry({5, 8});
        Field field3(field1);
        field1 = field2;
        std::cout << field3.getCell({5, 5}).getPassable() << "\n";
        std::cout << field1.getEntry().getX() << " " << field1.getEntry().getY() << "\n\n";
    }

    {
        Field field = Field(6, 6);
        std::cout << field.getExit().getX() << " " << field.getExit().getY() << "\n";
        field = Field(18, 18);
        std::cout << field.getExit().getX() << " " << field.getExit().getY() << "\n";


    }
    return 0;
}
