# CXX = g++
# CXXFLAGS = -std=c++14 -Wall
 
# TARGET = logcat_parser2
# SRC = main.cpp LogEntry.cpp LogParser.cpp LogFilter.cpp LogcatApp.cpp
# OBJ = $(SRC:.cpp=.o)
 
# all: $(TARGET)
 
# $(TARGET): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $@ $^
 
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $<
 
# clean:
# 	rm -f $(OBJ) $(TARGET)
CXX = g++
CXXFLAGS = -std=c++14 -Wall
GTEST_LIBS = -lgtest -lgtest_main -pthread

TARGET = logcat_parser2
TEST_TARGET = test_log

SRC = main.cpp LogEntry.cpp LogParser.cpp LogFilter.cpp LogcatApp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

test_log: test_log.cpp LogEntry.o LogParser.o LogFilter.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

clean:
	rm -f $(OBJ) $(TARGET) $(TEST_TARGET)
