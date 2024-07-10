#ifndef LOGFILTER_H
#define LOGFILTER_H
 
#include "ILogFilter.h"
 
class LogFilter : public ILogFilter {
public:
    std::vector<LogEntry> filterByPid(const std::vector<LogEntry>& entries, int pid) override;
    std::vector<LogEntry> filterByTid(const std::vector<LogEntry>& entries, int tid) override;
    std::vector<LogEntry> filterByTimeRange(const std::vector<LogEntry>& entries, const std::string& startTime, const std::string& endTime) override;
};
 
#endif // LOGFILTER_H