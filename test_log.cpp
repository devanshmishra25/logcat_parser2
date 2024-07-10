#include "LogEntry.h"
#include "LogParser.h"
#include "LogFilter.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <fstream>

// Helper function to create a temporary log file
std::string createTempLogFile(const std::string& content) {
    std::ofstream tempFile("temp_log.txt");
    tempFile << content;
    tempFile.close();
    return "temp_log.txt";
}

// Mock data for testing
const std::string logLine = "03-12 04:08:58.330 2313 2313 E PhoneInterfaceManager: [PhoneIntfMgr] getCarrierPackageNamesForIntentAndPhone: No UICC";
const std::string logFileContent = "03-12 04:08:58.330 2313 2313 E PhoneInterfaceManager: [PhoneIntfMgr] getCarrierPackageNamesForIntentAndPhone: No UICC\n"
                                   "03-12 04:08:58.331 1298 1441 D CAR.PACKAGE: Null Activities for com.gm.hmianalytics\n";

// Test LogEntry class
TEST(LogEntryTest, FromLogLine) {
    LogEntry entry = LogEntry::fromLogLine(logLine);
    EXPECT_EQ(entry.matchesPid(2313), true);
    EXPECT_EQ(entry.matchesTid(2313), true);
    EXPECT_EQ(entry.isWithinTimeRange("04:08:58.330", "04:08:58.330"), true);
}

TEST(LogEntryTest, MatchesPid) {
    LogEntry entry = LogEntry::fromLogLine(logLine);
    EXPECT_EQ(entry.matchesPid(2313), true);
    EXPECT_EQ(entry.matchesPid(1234), false);
}

TEST(LogEntryTest, MatchesTid) {
    LogEntry entry = LogEntry::fromLogLine(logLine);
    EXPECT_EQ(entry.matchesTid(2313), true);
    EXPECT_EQ(entry.matchesTid(1234), false);
}

// Test LogParser class
TEST(LogParserTest, Parse) {
    std::string tempFilePath = createTempLogFile(logFileContent);
    LogParser parser;
    std::vector<LogEntry> entries = parser.parse(tempFilePath);
    EXPECT_EQ(entries.size(), 2);
    EXPECT_EQ(entries[0].matchesPid(2313), true);
    EXPECT_EQ(entries[1].matchesTid(1441), true);
    std::remove(tempFilePath.c_str());
}

// Test LogFilter class
TEST(LogFilterTest, FilterByPid) {
    std::string tempFilePath = createTempLogFile(logFileContent);
    LogParser parser;
    std::vector<LogEntry> entries = parser.parse(tempFilePath);
    LogFilter filter;
    std::vector<LogEntry> filteredEntries = filter.filterByPid(entries, 2313);
    EXPECT_EQ(filteredEntries.size(), 1);
    EXPECT_EQ(filteredEntries[0].matchesPid(2313), true);
    std::remove(tempFilePath.c_str());
}

TEST(LogFilterTest, FilterByTimeRange) {
    std::string tempFilePath = createTempLogFile(logFileContent);
    LogParser parser;
    std::vector<LogEntry> entries = parser.parse(tempFilePath);
    LogFilter filter;
    std::vector<LogEntry> filteredEntries = filter.filterByTimeRange(entries, "04:08:58.330", "04:08:58.331");
    EXPECT_EQ(filteredEntries.size(), 2);
    EXPECT_EQ(filteredEntries[0].isWithinTimeRange("04:08:58.330", "04:08:58.331"), true);
    EXPECT_EQ(filteredEntries[1].isWithinTimeRange("04:08:58.330", "04:08:58.331"), true);
    std::remove(tempFilePath.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
