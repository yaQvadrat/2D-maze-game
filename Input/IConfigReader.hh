#ifndef I_CONFIG_READER_HH
#define I_CONFIG_READER_HH

#include <map>
#include <memory>

class ICommand;

enum class Command {MVUP = 0, MVDOWN, MVLEFT, MVRIGHT, EXIT, RESTART, COUNT};

class IConfigReader
{
public:
    virtual std::map<char, std::shared_ptr<ICommand>> readConfig() = 0;
};

#endif
