#ifndef GAME_LOGGER_HH
#define GAME_LOGGER_HH

#include "ILogger.hh"
#include "ILoggerOutput.hh"
#include <list>
#include <memory>

class AbstractLogMessage;

class GameLogger: public ILogger
{
    std::list<std::unique_ptr<ILoggerOutput>> output_sources;
public:
    void initLogger() override;
    void logMessage(const AbstractLogMessage &msg) override;
};

#endif
