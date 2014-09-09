CXX=g++
CXXFLAGS=-Wall
OBJS=main.o
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
        $(CXX) $(CXXFLAGS) $(OBJS) -o $@


clean:
        rm -f $(EXECUTABLE)
        rm -f $(OBJS)

main.o: main.cpp