#include "LogcatApp.h"
#include "LogParser.h"
#include "LogFilter.h"
 
int main(int argc, char* argv[]) {
    ILogParser* parser = new LogParser();
    ILogFilter* filter = new LogFilter();
    LogcatApp app(argc, argv, parser, filter);
    app.run();
    return 0;
}


