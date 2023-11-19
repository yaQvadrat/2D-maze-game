#include "FieldCreator.hh"
#include "Cell.hh"
#include "../Event/ThrowAsideEvent.hh"
#include "../Event/TrapEvent.hh"
#include "../Event/PointsEvent.hh"

std::unique_ptr<Field> FieldCreator::getLevel(int level)
{
    constexpr int FIRST_LEVEL = 1;
    constexpr int SECOND_LEVEL = 2;

    switch (level)
    {
    case FIRST_LEVEL:
        return firstLevel();
        break;
    
    case SECOND_LEVEL:
        return secondLevel();
        break;
    }
    
    return firstLevel();
}

std::unique_ptr<Field> FieldCreator::firstLevel()
{
    std::unique_ptr field = std::make_unique<Field>(5, 5);
    field->setPassableBlock(false, {1, 3}, {3, 3});
    field->setPassableBlock(false, {1, 0}, {3, 0});
    field->setEntry({0, 4});
    field->setExit({4, 0});
    field->getCell({0, 3}) = Cell(true, new ThrowAsideEvent(Direction::UP));
    field->getCell({1, 1}) = Cell(true, new ThrowAsideEvent(Direction::RIGHT));
    field->getCell({2, 1}) = Cell(true, new ThrowAsideEvent(Direction::RIGHT));
    for (int y = 0; y <= 2; ++y)
        field->getCell({0, y}) = Cell(true, new PointsEvent(100));
    field->getCell({4, 1}) = Cell(true, new PointsEvent(100));
    field->getCell({4, 4}) = Cell(true, new TrapEvent(50));
    field->getCell({3, 2}) = Cell(true, new TrapEvent(50));
    return field;
}

std::unique_ptr<Field> FieldCreator::secondLevel()
{
    std::unique_ptr field = std::make_unique<Field>(10, 10);
    field->setPassableBlock(false, {1, 0}, {9, 2});
    field->setPassableBlock(false, {0, 7}, {5, 9});
    for (int x = 1; x <= 8; ++x)
        field->getCell({x, 3}) = Cell(true, new ThrowAsideEvent(Direction::RIGHT));
    field->getCell({9, 3}) = Cell(true, new TrapEvent(99));
    field->getCell({0, 6}) = Cell(true, new TrapEvent);
    for (int y = 4; y <= 8; ++y)
        field->getCell({9, y}) = Cell(true, new ThrowAsideEvent(Direction::UP));
    for (int x = 0; x <= 4; ++x)
        field->getCell({x, 5}) = Cell(true, new PointsEvent);
    for (int x = 5; x <= 8; ++x)
        field->getCell({x, 5}) = Cell(true, new PointsEvent(100));
    field->getCell({6, 5}) = Cell(true, new TrapEvent);
    return field;
}
