CXX = mpic++
CXXFLAGS = -std=c++11 -g3 -Wall -I/usr/include/opencv4/opencv -I/usr/include/opencv4
MKDIR = mkdir -p

LIBS = libboost-dev

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all