#include "LogParser.h"
#include <fstream>
#include <iostream>
 
std::vector<LogEntry> LogParser::parse(const std::string& filePath) {
    std::vector<LogEntry> entries;
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return entries;
    }
    std::string line;
    while (std::getline(file, line)) {
        entries.push_back(LogEntry::fromLogLine(line));
    }
    return entries;
}