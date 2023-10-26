#include "Player/Player.hh"
#include "Controller/PlayerController.hh"
#include "Field/Cell.hh"
#include "Field/Field.hh"
#include "Event/PointsEvent.hh"
#include "Event/ThrowAsideEvent.hh"
#include "Field/FieldCreator.hh"
#include <iostream>


int main()
{
    // PointsEvent correct test
    {
        Field field;
        field.getCell({0, 1}) = Cell(true, new PointsEvent(100));
        Player player;
        PlayerController controller(field, player);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        controller.move(Direction::UP);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        controller.move(Direction::DOWN);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        controller.move(Direction::UP);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n\n\n";
    }
    // ThrowAsideEvent correct test
    {
        Field field(6, 6);
        field.getCell({1, 0}) = Cell(true, new ThrowAsideEvent(Direction::UP));
        field.getCell({1, 1}) = Cell(true, new ThrowAsideEvent(Direction::RIGHT));
        field.getCell({2, 1}) = Cell(true, new ThrowAsideEvent(Direction::DOWN));
        field.getCell({2, 0}) = Cell(true, new ThrowAsideEvent(Direction::LEFT));
        Player player;
        PlayerController controller(field, player);
        std::cout << controller.getCoordinates() << "\n";
        controller.move(Direction::RIGHT);
        std::cout << controller.getCoordinates() << "\n";
        field.getCell({0, 0}) = Cell(true, new ThrowAsideEvent(Direction::UP));
        controller.move(Direction::LEFT);
        std::cout << controller.getCoordinates() << "\n";
        field.getCell({0, 2}) = Cell(true, new ThrowAsideEvent(Direction::LEFT));
        controller.move(Direction::UP);
        std::cout << controller.getCoordinates() << "\n\n\n";
    }
    // FieldCreator + different events test
    {
        FieldCreator creator;
        Player player;
        Field field = creator.secondLevel();
        PlayerController controller (field, player);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        for (size_t k = 0; k < 5; ++k)
            controller.move(Direction::UP);
        controller.move(Direction::RIGHT);
        controller.move(Direction::RIGHT);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        std::cout << "Health:" << player.get(Option::HEALTH).getValue() << "\n";
        controller.move(Direction::DOWN);
        controller.move(Direction::DOWN);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Health:" << player.get(Option::HEALTH).getValue() << "\n";
        controller.move(Direction::UP);
        std::cout << controller.getCoordinates() << "\n";
        std::cout << "Points: " << player.get(Option::POINTS).getValue() << "\n";
        std::cout << "Health:" << player.get(Option::HEALTH).getValue() << "\n\n\n";
    }
    FieldCreator creator;
    Field field = creator.firstLevel();
    Player player;
    PlayerController controller(field, player);
    for (int i = 0; i < 5; ++i)
        controller.move(Direction::RIGHT);
    controller.move(Direction::DOWN);
    controller.move(Direction::DOWN);
    controller.move(Direction::LEFT);
    std::cout << "Health:" << player.get(Option::HEALTH).getValue() << "\n";
    std::cout << std::boolalpha << player.isAlive() << "\n";
    return 0;
}
