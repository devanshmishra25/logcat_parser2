#ifndef LOGCATAPP_H
#define LOGCATAPP_H
 
#include "ILogParser.h"
#include "ILogFilter.h"
#include <string>
 
class LogcatApp {
public:
    LogcatApp(int argc, char* argv[], ILogParser* parser, ILogFilter* filter);
    //The constructor takes command-line arguments along with pointers to ILogParser and ILogFilter implementations. 
    //This allows for ****dependency injection****, making the class more flexible and easier to test.
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
    //A helper method to parse the command-line arguments and set up the application state accordingly.
};
 
#endif // LOGCATAPP_H

/*
Role of the LogcatApp Class
LogcatApp orchestrates the application's functionality, tying together command-line input, log parsing, and log filtering into a coherent workflow. 
By decoupling the parsing and filtering logic into separate classes and using interface pointers,
LogcatApp remains agnostic of the specific implementations, adhering to principles like separation of concerns and inversion of control.
*/