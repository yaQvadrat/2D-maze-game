#include "FileLoggerOutput.hh"
#include "AbstractLogMessage.hh"

FileLoggerOutput::FileLoggerOutput(const std::string &filename): file{filename}
{
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);
}

FileLoggerOutput::~FileLoggerOutput()
{
    file.close();
}

void FileLoggerOutput::log(const std::string &logs)
{
    file << logs;
}