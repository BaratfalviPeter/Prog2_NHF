CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -fsanitize=address
LDFLAGS = -fsanitize=address

TARGET = filmtar
SOURCES = main.cpp Film.cpp Katalogus.cpp Kedvencek.cpp Logika.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)