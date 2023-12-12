#ifndef GAME_LOGGER_HH
#define GAME_LOGGER_HH

#include "ILogger.hh"
#include "ILoggerOutput.hh"
#include <sstream>
#include <list>
#include <memory>

class AbstractLogMessage;

class GameLogger: public ILogger
{
    std::list<std::unique_ptr<ILoggerOutput>> output_sources;
    std::ostringstream logs;
public:
    void clearBuffer();
    void initLogger() override;
    void logMessage(const AbstractLogMessage &msg) override;
    void releaseLogs() override;
};

#endif
