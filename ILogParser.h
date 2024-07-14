#ifndef ILOGPARSER_H
#define ILOGPARSER_H
 
#include "LogEntry.h"
#include <vector>
#include <string>
 
class ILogParser {
public:
    virtual ~ILogParser() = default; //It's crucial for interfaces where inheritance is used to 
                                     // ensure proper cleanup of derived class objects through base class pointers.


    virtual std::vector<LogEntry> parse(const std::string& filePath) = 0;
    // This function is expected to take a file path as input and return a vector of LogEntry objects, representing the parsed log entries
};
 
#endif // ILOGPARSER_H

