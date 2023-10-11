#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include "Field/Cell.hh"
#include "Field/Field.hh"
#include "Event/PointsEvent.hh"
#include <iostream>


int main()
{
    /*// LAB1
    Player my_player;
    std::cout << my_player.getValue(Option::HEALTH) << ": HP| " << my_player.getValue(Option::POINTS) << ": POINTS|\n";
    my_player.setValue(Option::HEALTH, 90);
    my_player.getValue(Option::HEALTH);
    std::cout << my_player.getValue(Option::HEALTH) << ": HP|\n";
    my_player.setValue(Option::POINTS, 500000);
    std::cout << my_player.getValue(Option::POINTS) << ": POINTS|\n";
    */

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
    return 0;
}
