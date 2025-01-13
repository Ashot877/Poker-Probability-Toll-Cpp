TARGET = game
SRC = main.cpp deck.cpp monte_carlo.cpp b_combination.cpp check_combination.cpp compare_.cpp
OBJ = $(SRC:.cpp=.o)
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
