#include "LogParser.h"
#include <fstream> // Includes the standard file stream library to handle file input operations.
#include <iostream>
 
std::vector<LogEntry> LogParser::parse(const std::string& filePath) {
    std::vector<LogEntry> entries; // A vector to store the parsed log entries
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return entries; // return an empty vector
    }
    std::string line;
    while (std::getline(file, line)) {
        entries.push_back(LogEntry::fromLogLine(line)); //Parses the line to create a LogEntry object using the static method fromLogLine 
                                                        //and adds it to the entries vector.
    }
    return entries;
}

/*
Role of This Implementation
The LogParser::parse method efficiently handles reading from a log file and converting each line into a structured LogEntry object. 
It encapsulates the file reading and parsing logic within the class, adhering to the single responsibility principle 
by keeping file parsing separate from other functionalities like filtering or displaying the logs.
*/