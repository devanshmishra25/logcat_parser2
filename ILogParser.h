#ifndef ILOGPARSER_H
#define ILOGPARSER_H
 
#include "LogEntry.h"
#include <vector>
#include <string>
 
class ILogParser {
public:
    virtual ~ILogParser() = default;
    virtual std::vector<LogEntry> parse(const std::string& filePath) = 0;
};
 
#endif // ILOGPARSER_H

