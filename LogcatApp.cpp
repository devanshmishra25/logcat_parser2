#include "LogcatApp.h"
#include <iostream>
#include <vector>
#include <cstdlib>
 
LogcatApp::LogcatApp(int argc, char* argv[], ILogParser* parser, ILogFilter* filter)
    : pid(-1), tid(-1), filterByPid(false), filterByTid(false), filterByTimeRange(false), parser(parser), filter(filter) {
    parseCommandLineArguments(argc, argv);
}
 
LogcatApp::~LogcatApp() {
    delete parser;
    delete filter;
}
 
void LogcatApp::parseCommandLineArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--file" && i + 1 < argc) {
            filePath = argv[++i];
        } else if (arg == "--pid" && i + 1 < argc) {
            pid = std::atoi(argv[++i]);
            filterByPid = true;
        } else if (arg == "--tid" && i + 1 < argc) {
            tid = std::atoi(argv[++i]);
            filterByTid = true;
        } else if (arg == "--start-time" && i + 1 < argc) {
            startTime = argv[++i];
            filterByTimeRange = true;
        } else if (arg == "--end-time" && i + 1 < argc) {
            endTime = argv[++i];
            filterByTimeRange = true;
        }
    }
}
 
void LogcatApp::run() {
    std::vector<LogEntry> entries = parser->parse(filePath);
 
    if (filterByPid) {
        entries = filter->filterByPid(entries, pid);
    }
    if (filterByTid) {
        entries = filter->filterByTid(entries, tid);
    }
    if (filterByTimeRange) {
        entries = filter->filterByTimeRange(entries, startTime, endTime);
    }
 
    for (const auto& entry : entries) {
        std::cout << entry << std::endl;
    }
}