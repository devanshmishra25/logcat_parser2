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

/*
The LogFilter class serves as a concrete implementation of the ILogFilter interface,
providing specific filtering logic for log entries. This separation of filtering logic into its own class allows 
for a modular design where the parsing and filtering functionalities are cleanly separated. 
This design enhances maintainability and testing, as each class focuses on a single responsibility.
*/