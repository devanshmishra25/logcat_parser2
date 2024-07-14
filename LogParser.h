#ifndef LOGPARSER_H
#define LOGPARSER_H
 
#include "ILogParser.h"
 
class LogParser : public ILogParser {
public:
    std::vector<LogEntry> parse(const std::string& filePath) override;
};
 
#endif // LOGPARSER_H

/*
Role of logparser class

LogParser serves as a concrete implementation of the ILogParser interface. Its primary role is to take a file path, 
read the log entries from this file, and convert them into LogEntry objects. 

The overriding of the parse method ensures that LogParser adheres to the contract established by the ILogParser interface,
specifically tailored to handle the reading and parsing operations defined.
*/