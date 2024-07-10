#ifndef LOGENTRY_H
#define LOGENTRY_H
 
#include <string>
#include <iostream>
#include <vector>
 
class LogEntry {
public:
    LogEntry(const std::string& date, const std::string& time, int pid, int tid, const std::string& level, const std::string& tag, const std::string& message);
    static LogEntry fromLogLine(const std::string& logLine); // calls directly and not by object of class (reason: static)
    bool matchesPid(int pid) const;
    bool matchesTid(int tid) const;
    bool isWithinTimeRange(const std::string& startTime, const std::string& endTime) const;
    friend std::ostream& operator<<(std::ostream& os, const LogEntry& entry);
 
private:
    std::string date;
    std::string time;
    int pid;
    int tid;
    std::string level;
    std::string tag;
    std::string message;
};
 
#endif // LOGENTRY_H