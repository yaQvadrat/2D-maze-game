#include "ConsoleInputReader.hh"
#include <iostream>
#include <unistd.h>

ConsoleInputReader::ConsoleInputReader()
{
    tcgetattr(STDIN_FILENO, &default_attr);
}

char ConsoleInputReader::read()
{
    termios new_attr = default_attr;
    new_attr.c_lflag &= (~ECHO & ~ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);
    char key = std::getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &default_attr);
    return key;
} 
