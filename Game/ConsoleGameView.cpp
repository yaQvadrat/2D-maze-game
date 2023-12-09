#include "ConsoleGameView.hh"
#include "../Event/PointsEvent.hh"
#include "../Event/ThrowAsideEvent.hh"
#include "../Event/TrapEvent.hh"
#include "../Controller/PlayerController.hh"
#include "../Player/Player.hh"
#include "../Field/Field.hh"
#include "../Field/Cell.hh"
#include <sstream>
#include <typeinfo>

Object ConsoleGameView::getObject(Coordinates cell_coord, Coordinates player_coord, const Field &field)
{
    if (cell_coord == player_coord)
        return Object::PLAYER;
    
    Cell &cell = field.getCell(cell_coord);
    if (!cell.getPassable())
        return Object::WALL;
    
    if (cell_coord == field.getEntry()) {
        return Object::START;
    } else if (cell_coord == field.getExit()) {
        return Object::EXIT;
    }

    const IEvent *event = cell.getEvent();
    if (!event) {
        return Object::CELL;
    } else if (typeid(*event) == typeid(ThrowAsideEvent)) {
        Direction direction = static_cast<const ThrowAsideEvent*>(event)->getDirection();
        switch (direction)
        {
        case Direction::UP:
            return Object::THROW_UP;
        
        case Direction::DOWN:
            return Object::THROW_DOWN;
        
        case Direction::LEFT:
            return Object::THROW_LEFT;
        
        case Direction::RIGHT:
            return Object::THROW_RIGHT;
        }
    } else if (typeid(*event) == typeid(TrapEvent)) {
        return Object::TRAP_EVENT;
    } else if (typeid(*event) == typeid(PointsEvent)) {
        return Object::POINTS_EVENT;
    }
    
    return Object::CELL;
}

void ConsoleGameView::displayGame(const PlayerController &controller)
{
    const Field &field = controller.getField();
    const Player &player = controller.getPlayer();
    int h = field.getHeight();
    int w = field.getWidth();
    Coordinates player_coord = controller.getCoordinates();

    std::ostringstream buffer;
    buffer << "\033c";
    buffer << "HP: " << player.get(Option::HEALTH).getValue() << " ||| XP: " << player.get(Option::POINTS).getValue() << "\n\n";
    for (int y = h - 1; y >= 0; --y) {
        for (int x = 0; x < w; ++x) {
            buffer << object_view[getObject({x, y}, player_coord, field)];
        }
        buffer << "\n";
    }
    std::cout << buffer.str();
}

void ConsoleGameView::displayMenu()
{
    std::cout << "MENU\n1. FIRST LEVEL\n2. SECOND LEVEL\n3. THIRD LEVEL\nPRESS Q TO QUIT\n";
}

void ConsoleGameView::displayWinMenu()
{
    std::cout << "\nVICTORY\n\n";
    displayMenu();
}

void ConsoleGameView::displayDefeatMenu()
{
    std::cout << "\nDEFEAT\n\n";
    displayMenu();
}

void ConsoleGameView::initView()
{
    std::cout << "\033c";
}

void ConsoleGameView::displayRestartMenu()
{
    std::cout << "\nRESTART\n\n";
    displayMenu();
}
