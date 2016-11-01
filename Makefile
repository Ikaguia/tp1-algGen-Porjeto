CPP = g++

OBJS = main.cpp tester.cpp

FLAGS = -std=c++11 -Wall -Wno-unused-result -O2

TARGET = testIA

all:
	$(CPP) $(FLAGS) $(OBJS) -o $(TARGET)