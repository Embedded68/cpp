CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

all: count_islands rotate_matrix

count_islands: src/count_islands.cpp
    $(CXX) $(CXXFLAGS) -o count_islands src/count_islands.cpp

rotate_matrix: src/rotate_matrix.cpp
    $(CXX) $(CXXFLAGS) -o rotate_matrix src/rotate_matrix.cpp

clean:
    rm -f count_islands rotate_matrix