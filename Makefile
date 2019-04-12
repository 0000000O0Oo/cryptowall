CXX=g++
CXXFLAGS=-std=c++11 -flto -Os -Wall -lcryptopp

MALWARE_SRC=$(wildcard src/malware/*.cc)
SERVER_SRC=$(wildcard src/server/*.cc)
DECRYPTOR_SRC=src/decryptor.cc \
	      src/malware/file_encryptor.cc \
	      src/malware/util.cc

BUILD=build
MALWARE=$(BUILD)/DailyAllowance
SERVER=$(BUILD)/server
DECRYPTOR=$(BUILD)/decryptor

all:
	make malware
	make server
	make decryptor

malware:
	mkdir -p $(BUILD)
	./scripts/generate_note_h.py
	$(CXX) -o $(MALWARE) $(MALWARE_SRC) $(CXXFLAGS)

server:
	mkdir -p $(BUILD)
	$(CXX) -o $(SERVER) $(SERVER_SRC) $(CXXFLAGS)

decryptor:
	mkdir -p $(BUILD)
	$(CXX) -o $(DECRYPTOR) $(DECRYPTOR_SRC) $(CXXFLAGS)

%.clean:
	rm -rf $(BUILD)
	rm $(MALWARE)
	rm $(DECRYPTOR)
	rm $(SERVER)
