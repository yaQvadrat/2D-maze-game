#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include <iostream>

class Cell
{

};

int main()
{
    Player my_player;
    std::cout << my_player.getValue(Option::HEALTH) << " " << my_player.getValue(Option::POINTS) << "\n";
    my_player.setValue(Option::HEALTH, 90);
    my_player.getValue(Option::HEALTH);
    std::cout << my_player.getValue(Option::HEALTH) << "\n";
    PlayerController controller(my_player);
    Coordinates coord = controller.getCoordinates();
    std::cout << coord.getX() << " " << coord.getY() << "\n";
    my_player.setValue(Option::POINTS, 500000);
    std::cout << my_player.getValue(Option::POINTS) << "\n";
    return 0;
}
