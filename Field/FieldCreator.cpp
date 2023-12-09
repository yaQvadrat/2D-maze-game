#include "FieldCreator.hh"
#include "Cell.hh"
#include "../Event/ThrowAsideEvent.hh"
#include "../Event/TrapEvent.hh"
#include "../Event/PointsEvent.hh"

std::unique_ptr<Field> FieldCreator::getLevel(int level)
{
    constexpr int FIRST_LEVEL = 1;
    constexpr int SECOND_LEVEL = 2;
    constexpr int THIRD_LEVEL = 3;

    switch (level)
    {
    case FIRST_LEVEL:
        return firstLevel();
    
    case SECOND_LEVEL:
        return secondLevel();
    
    case THIRD_LEVEL:
        return thirdLevel();
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
    std::unique_ptr field = std::make_unique<Field>(11, 11);
    field->setExit({9, 9});
    field->setEntry({1, 1});

    field->setPassableBlock(false, {0, 0}, {0, 10});
    field->setPassableBlock(false, {0, 10}, {10, 10});
    field->setPassableBlock(false, {10, 0}, {10, 10});
    field->setPassableBlock(false, {0, 0}, {10, 0});
    field->setPassableBlock(false, {1, 2}, {1, 3});
    field->setPassableBlock(false, {5, 6}, {7, 9});

    for (int x = 4; x <= 8; ++x)
        field->getCell({x, 3}) = Cell(true, new ThrowAsideEvent(Direction::RIGHT));
    field->getCell({9, 3}) = Cell(true, new TrapEvent(99));
    field->getCell({1, 6}) = Cell(true, new TrapEvent);
    for (int y = 4; y <= 8; ++y)
        field->getCell({9, y}) = Cell(true, new ThrowAsideEvent(Direction::UP));
    for (int x = 1; x <= 4; ++x)
        field->getCell({x, 5}) = Cell(true, new PointsEvent);
    for (int x = 5; x <= 8; ++x)
        field->getCell({x, 5}) = Cell(true, new PointsEvent(100));
    field->getCell({6, 5}) = Cell(true, new TrapEvent);
    return field;
}

std::unique_ptr<Field> FieldCreator::thirdLevel()
{
    std::unique_ptr field = std::make_unique<Field>(16, 16);
    field->setEntry({15, 0});
    field->setPassableBlock(false, {0, 5}, {4, 7});
    field->setPassableBlock(false, {7, 5}, {15, 7});
    field->setPassableBlock(false, {7, 7}, {9, 13});
    field->setPassableBlock(false, {11, 10}, {13, 15});
    field->getCell({14, 15}) = Cell(true, new TrapEvent(100));
    field->getCell({14, 15}) = Cell(true, new TrapEvent(100));
    field->getCell({5, 15}) = Cell(true, new TrapEvent(100));
    for (int i = 5; i <= 14; ++i)
        field->getCell({5, i}) = Cell(true, new ThrowAsideEvent(Direction::UP));
    for (int i = 0; i <= 4; ++i) {
        for (int j = 0; j <= 4; ++j)
            field->getCell({i, j}) = Cell(true, new PointsEvent(100));
    }
    field->getCell({2, 4}) = Cell(true, new ThrowAsideEvent(Direction::DOWN));
    field->getCell({2, 3}) = Cell(true, new ThrowAsideEvent(Direction::DOWN));
    field->getCell({2, 2}) = Cell(true, new TrapEvent(100));
    return field;
}
