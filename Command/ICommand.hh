#ifndef I_COMMAND_HH
#define I_COMMAND_HH

class Game;

class ICommand
{
public:
    virtual void execute(Game &game) = 0;
};

#endif
