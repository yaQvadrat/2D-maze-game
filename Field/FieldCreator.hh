#ifndef FIELD_CREATOR_HH
#define FIELD_CREATOR_HH

#include "Field.hh"
#include <memory>

class FieldCreator
{
public:
    std::unique_ptr<Field> getLevel(int level);
    std::unique_ptr<Field> firstLevel();
    std::unique_ptr<Field> secondLevel();
};

#endif
