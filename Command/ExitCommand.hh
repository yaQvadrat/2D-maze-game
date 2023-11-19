#ifndef EXIT_COMMAND_HH
#define EXIT_COMMAND_HH

#include "ICommand.hh"

class ExitCommand: public ICommand
{
public:
    void execute(Game &game) override;
};

#endif
