#include "LogFilter.h"
 
std::vector<LogEntry> LogFilter::filterByPid(const std::vector<LogEntry>& entries, int pid) {
    std::vector<LogEntry> filteredEntries;
    for (const auto& entry : entries) {
        if (entry.matchesPid(pid)) {
            filteredEntries.push_back(entry);
        }
    }
    return filteredEntries;
}
 
std::vector<LogEntry> LogFilter::filterByTid(const std::vector<LogEntry>& entries, int tid) {
    std::vector<LogEntry> filteredEntries;
    for (const auto& entry : entries) {
        if (entry.matchesTid(tid)) {
            filteredEntries.push_back(entry);
        }
    }
    return filteredEntries;
}
 
std::vector<LogEntry> LogFilter::filterByTimeRange(const std::vector<LogEntry>& entries, const std::string& startTime, const std::string& endTime) {
    std::vector<LogEntry> filteredEntries;
    for (const auto& entry : entries) {
        if (entry.isWithinTimeRange(startTime, endTime)) {
            filteredEntries.push_back(entry);
        }
    }
    return filteredEntries;
}