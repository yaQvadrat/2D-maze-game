#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include "Field/Cell.hh"
#include "Field/Field.hh"
#include "Event/PointsEvent.hh"
#include <iostream>


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
