#include "loggerobserver.h"
#include "Logger/filelogger.h"
#include "Logger/consolelogger.h"

LoggerObserver::~LoggerObserver()
{
    clear();
    logs.clear();
}

void LoggerObserver::addLogger(Logger *log)
{
    if(dynamic_cast<FileLogger *>(log))
        for(auto tmp : logs) {
            if(dynamic_cast<FileLogger *>(tmp) && ((FileLogger *)tmp)->getFileName() == ((FileLogger*)log)->getFileName())
                return;
        }
    else if(dynamic_cast<ConsoleLogger*>(log)){
        for(auto tmp: logs)
            if(dynamic_cast<ConsoleLogger *>(tmp)) {
                return;
            }
    }
    logs.insert(log);
}

void LoggerObserver::deleteLogger(Logger *log)
{
    if(dynamic_cast<FileLogger *>(log))
        for(auto tmp : logs) {
            if(dynamic_cast<FileLogger *>(tmp) && ((FileLogger *)tmp)->getFileName() == ((FileLogger*)log)->getFileName())
                log = tmp;
        }
    else if(dynamic_cast<ConsoleLogger*>(log)){
        for(auto tmp: logs)
            if(dynamic_cast<ConsoleLogger *>(tmp)) {
                log = tmp;
            }
    }
    delete log;
    logs.erase(log);
}

void LoggerObserver::deleteLevel(Level level)
{
    if(findLevel(level) != -1)
    for(int i = findLevel(level); i < (int)levels.size() - 1; i++) {
        levels[i] = levels[i + 1];
    }
    levels.pop_back();
}

void LoggerObserver::addLevel(Level level)
{
    if(findLevel(level) == -1)
        levels.push_back(level);
}

void LoggerObserver::update(Level level, std::string s)
{
    if(findLevel(level) != -1)
        for(auto t : logs)
            t->log(level, s);
}

std::string LoggerObserver::toString()
{
    std::string s = "OBS_S:\n\tLEVELS: ";

    for(int i = 0; i < (int)levels.size(); i++) {
        s += std::to_string((int)levels[i]) + " ";
    }
    s+="\n\tLOGGERS:\n";
    for(auto i : logs) {
        s += i->toString();
    }
    s+= "OBS_E\n";
    return s;
}

int LoggerObserver::findLevel(Level level)
{
    for(int i = 0; i < (int)levels.size(); i++) {
        if(levels[i] == level)
            return i;
    }
    return -1;
}

void LoggerObserver::clear()
{
    for(Logger* t :logs) {
        delete t;
    }
}
