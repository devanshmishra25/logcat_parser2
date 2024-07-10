#ifndef LOGPARSER_H
#define LOGPARSER_H
 
#include "ILogParser.h"
 
class LogParser : public ILogParser {
public:
    std::vector<LogEntry> parse(const std::string& filePath) override;
};
 
#endif // LOGPARSER_H