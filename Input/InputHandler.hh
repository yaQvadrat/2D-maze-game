#ifndef INPUT_HANDLER_HH
#define INPUT_HANDLER_HH

#include <map>
#include <memory>

class ICommand;
class IConfigReader;
class Game;

class InputHandler
{
    std::map<char, std::shared_ptr<ICommand>> key_mapping;

public:
    InputHandler(IConfigReader &config_reader);

    void handleInput(char key, Game &game);
};

#endif
