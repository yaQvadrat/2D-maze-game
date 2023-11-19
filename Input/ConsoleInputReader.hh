#ifndef CONSOLE_INPUT_READER_HH
#define CONSOLE_INPUT_READER_HH

#include "IInputReader.hh"
#include <termios.h>

class ConsoleInputReader: public IInputReader
{
    termios default_attr;

public:
    ConsoleInputReader();

    char read() override;
};

#endif
