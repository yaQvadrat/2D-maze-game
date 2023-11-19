#ifndef RESTART_COMMAND_HH
#define RESTART_COMMAND_HH

#include "ICommand.hh"

class RestartCommand: public ICommand
{
public:
    void execute(Game &game) override;
};

#endif
