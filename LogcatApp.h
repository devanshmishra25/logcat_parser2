#ifndef LOGCATAPP_H
#define LOGCATAPP_H
 
#include "ILogParser.h"
#include "ILogFilter.h"
#include <string>
 
class LogcatApp {
public:
    LogcatApp(int argc, char* argv[], ILogParser* parser, ILogFilter* filter);
    ~LogcatApp();
    void run();
 
private:
    std::string filePath;
    int pid;
    int tid;
    std::string startTime;
    std::string endTime;
    bool filterByPid;
    bool filterByTid;
    bool filterByTimeRange;
    ILogParser* parser;
    ILogFilter* filter;
 
    void parseCommandLineArguments(int argc, char* argv[]);
};
 
#endif // LOGCATAPP_H