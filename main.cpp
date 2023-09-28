#include "Player.hh"
#include "PlayerController.hh"

int main()
{
    //Player class test
    Player firstPlayer;
    Player secondPlayer(150);
    Player thirdPlayer(200, 2);
    Player fourthPlayer(400, 3, 500);
    firstPlayer.set_points(40);
    secondPlayer.set_attempts(-5);
    thirdPlayer.set_points(50);

    std::cout << firstPlayer.get_health() << " " << firstPlayer.get_attempts() << " " << firstPlayer.get_points() << "\n";
    std::cout << secondPlayer.get_health() << " " << secondPlayer.get_attempts() << " " << secondPlayer.get_points() << "\n";
    std::cout << thirdPlayer.get_health() << " " << thirdPlayer.get_attempts() << " " << thirdPlayer.get_points() << "\n";
    std::cout << fourthPlayer.get_health() << " " << fourthPlayer.get_attempts() << " " << fourthPlayer.get_points() << "\n\n";

    //PlayerController class test
    PlayerController firstController(firstPlayer);
    PlayerController secondController(secondPlayer, {4, 4});
    firstController.change_coord({5, 5});
    std::pair<int, int> collected_coord = secondController.get_both_coord();
    std::cout << firstController.get_x() << " " << firstController.get_y() << "\n";
    std::cout << collected_coord.first << " " << collected_coord.second << "\n\n";
    secondController.change_attempts(2);
    secondController.change_health(-100);
    secondController.change_points(100);
    firstController.move(Direction::UP);
    firstController.move(Direction::RIGHT);
    std::cout << firstController.get_x() << " " << firstController.get_y() << "\n";
    std::cout << secondPlayer.get_health() << " " << secondPlayer.get_attempts() << " " << secondPlayer.get_points() << "\n";

}
