CXX = clang++
CXXFLAGS = -Wall -std=c++17
LFLAGS = -Wall

TARGET = tracking.o
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: $(SRCS) $(TARGET)

.PHONY: clean
clean:
	rm -rf *.o

$(TARGET): $(OBJS) Makefile
		$(CXX) $(LFLAGS) $(OBJS) -o $@
	
.cpp.o: $(SRCS) Makefile
		$(CXX) $(CXXFLAGS) -c $< -o $@ 