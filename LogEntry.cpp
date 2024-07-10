#include "LogEntry.h"
#include <sstream>
#include <iostream>

LogEntry::LogEntry(const std::string& date, const std::string& time, int pid, int tid, const std::string& level, const std::string& tag, const std::string& message)
    : date(date), time(time), pid(pid), tid(tid), level(level), tag(tag), message(message) {}

LogEntry LogEntry::fromLogLine(const std::string& logLine) {
    std::istringstream iss(logLine);
    std::string date, time, level, tag, message;
    int pid, tid;
    iss >> date >> time >> pid >> tid >> level;
    std::getline(iss, tag, ':');
    std::getline(iss, message);
    return LogEntry(date, time, pid, tid, level, tag, message);
}

bool LogEntry::matchesPid(int pid) const {
    return this->pid == pid;
}

bool LogEntry::matchesTid(int tid) const {
    return this->tid == tid;
}

int stringToInt(const std::string& str) {
    int result = 0;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            result = result * 10 + (c - '0');
        } else {
            break; // Stop at first non-digit character
        }
    }
    return result;
}

bool LogEntry::isWithinTimeRange(const std::string& startTime, const std::string& endTime) const {
    auto parseTime = [](const std::string& timeStr) {
        int hours = 0, minutes = 0, seconds = 0, milliseconds = 0;

        if (timeStr.length() >= 8) {
            hours = stringToInt(timeStr.substr(0, 2));
            minutes = stringToInt(timeStr.substr(3, 2));
            seconds = stringToInt(timeStr.substr(6, 2));
        }

        size_t pos = timeStr.find('.');
        if (pos != std::string::npos && pos + 1 < timeStr.size()) {
            milliseconds = stringToInt(timeStr.substr(pos + 1));
        }

        return hours * 3600000 + minutes * 60000 + seconds * 1000 + milliseconds;
    };

    int start = parseTime(startTime);
    int end = parseTime(endTime);
    int log = parseTime(time);

    return log >= start && log <= end;
}

std::ostream& operator<<(std::ostream& os, const LogEntry& entry) {
    os << entry.date << " " << entry.time << " " << entry.pid << " " << entry.tid << " " << entry.level << " " << entry.tag << ": " << entry.message;
    return os;
}