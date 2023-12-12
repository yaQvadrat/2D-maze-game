#ifndef INPUT_HANDLER_HH
#define INPUT_HANDLER_HH

#include "../Logger/ILoggable.hh"
#include <map>
#include <memory>
#include <list>

class ICommand;
class IConfigReader;
class Game;
class ILogger;

class InputHandler: public ILoggable
{
    std::map<char, std::shared_ptr<ICommand>> key_mapping;
    std::list<ILogger*> logger_list;
public:
    InputHandler(IConfigReader &config_reader);
    void handleInput(char key, Game &game);

    void attachLogger(ILogger *logger) override;
    void detachLogger(ILogger *logger) override;
    void sendLogMessage(const AbstractLogMessage &msg) override;
};

#endif
