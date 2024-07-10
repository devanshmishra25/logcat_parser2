#ifndef ILOGFILTER_H
#define ILOGFILTER_H
 
#include "LogEntry.h"
#include <vector>
#include <string>
 
class ILogFilter {
public:
    virtual ~ILogFilter() = default;
    virtual std::vector<LogEntry> filterByPid(const std::vector<LogEntry>& entries, int pid) = 0;
    virtual std::vector<LogEntry> filterByTid(const std::vector<LogEntry>& entries, int tid) = 0;
    virtual std::vector<LogEntry> filterByTimeRange(const std::vector<LogEntry>& entries, const std::string& startTime, const std::string& endTime) = 0;
};
 
#endif // ILOGFILTER_H