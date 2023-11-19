#ifndef CONFIG_READER_HH
#define CONFIG_READER_HH

#include "IConfigReader.hh"
#include <string>
#include <fstream>
#include <vector>
#include <set>

#define CONFIG_DELIM '='

enum class Command {MVUP = 0, MVDOWN, MVLEFT, MVRIGHT, EXIT, RESTART, COUNT};

class FileConfigReader: public IConfigReader
{
    std::ifstream file;
    std::set<std::string> assigned_actions;

    void tokenizeLine(const std::string &line, std::vector<std::string> &out);
    std::shared_ptr<ICommand> convertToCommand(const std::string &str);
public:
    FileConfigReader(const std::string &filename);
    ~FileConfigReader();
    FileConfigReader(const FileConfigReader&) = delete;
    FileConfigReader& operator=(const FileConfigReader&) = delete;
    FileConfigReader(FileConfigReader&&) = delete;
    FileConfigReader& operator=(FileConfigReader&&) = delete;

    std::map<char, std::shared_ptr<ICommand>> readConfig() override;
};

#endif
