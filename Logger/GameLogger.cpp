#include "GameLogger.hh"
#include "FileLoggerOutput.hh"
#include "ConsoleLoggerOutput.hh"
#include "AbstractLogMessage.hh"
#include <limits>
#include <iostream>

constexpr const char *DEFAULT_LOG_PATH = "../Logger/LOGS";

void GameLogger::logMessage(const AbstractLogMessage &msg)
{
    logs << msg << "\n";
}

void GameLogger::clearBuffer()
{
    logs.str("");
    logs.clear();
}

void GameLogger::releaseLogs()
{
    const std::string &str_logs = logs.str();
    clearBuffer();
    for (auto &concrete_writer: output_sources)
        concrete_writer->log(str_logs);
}

void GameLogger::initLogger()
{
    std::cout << "SELECT LOGGER MODE (DEFAULT NONE):\n1. CONSOLE\n2. FILE\n3. CONSOLE & FILE\n";
    char choice = std::getchar();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice)
    {
    case '1':
        output_sources.push_back(std::make_unique<ConsoleLoggerOutput>());
        break;
    
    case '2':
        output_sources.push_back(std::make_unique<FileLoggerOutput>(DEFAULT_LOG_PATH));
        break;

    case '3':
        output_sources.push_back(std::make_unique<ConsoleLoggerOutput>());
        output_sources.push_back(std::make_unique<FileLoggerOutput>(DEFAULT_LOG_PATH));
        break;
    }

    std::cout << "\033c";
}
