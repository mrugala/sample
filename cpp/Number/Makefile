GTEST_DIR = /home/mczaja/sandbox/googletest/googletest
USER_DIR = .
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++14

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I $(GTEST_DIR) $(CXXFLAGS) -c \
        $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
        $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

Number.o: Number.cpp Number.hpp
	$(CXX) -c -o Number.o Number.cpp

NumberTest.o: tests/NumberTest.cpp Number.hpp $(GTEST_HEADERS)
	$(CXX) -c -I $(GTEST_DIR)/include -o tests/NumberTest.o tests/NumberTest.cpp

runTests: tests/NumberTest.o Number.o gtest_main.a
	$(CXX) -o runTest -lpthread tests/NumberTest.o Number.o gtest_main.a

main.o : main.cpp Number.hpp
	$(CXX) -o main.o $(CXXFLAGS) -c main.cpp

all : main.o Number.o
	$(CXX) -o main Number.o main.o

clean :
	rm -f *.[oa] tests/*.o
