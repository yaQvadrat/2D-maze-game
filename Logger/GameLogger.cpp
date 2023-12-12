#include "GameLogger.hh"
#include "FileLoggerOutput.hh"
#include "ConsoleLoggerOutput.hh"
#include <limits>
#include <iostream>

constexpr const char *DEFAULT_LOG_PATH = "../Logger/LOGS";

void GameLogger::logMessage(const AbstractLogMessage &msg)
{
    for (auto &concrete_writer: output_sources)
        concrete_writer->log(msg);
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
