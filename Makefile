CXX=g++
CXXFLAGS=-std=c++11 -flto -Os -Wall -lcryptopp
SRC=$(wildcard src/*.cc)
BIN=main

all:
	./scripts/generate_note_h.py
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

%.clean:
	rm $(BIN)

run:
	./$(BIN)
