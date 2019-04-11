CXX=g++
CXXFLAGS=-std=c++11 -flto -Os -Wall -lcryptopp
SRC=$(wildcard src/*.cc)
BIN=main

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

%.clean:
	rm $(BIN)

run:
	./$(BIN)
