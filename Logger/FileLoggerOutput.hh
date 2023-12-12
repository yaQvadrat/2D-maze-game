#ifndef FILE_LOGGER_OUTPUT_HH
#define FILE_LOGGER_OUTPUT_HH

#include "ILoggerOutput.hh"
#include <fstream>

class AbstractLogMessage;

class FileLoggerOutput: public ILoggerOutput
{
    std::ofstream file;
public:
    FileLoggerOutput(const std::string &filename);
    ~FileLoggerOutput();
    void log(const std::string &logs) override;
};

#endif
