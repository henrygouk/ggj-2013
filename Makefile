SOURCES=$(shell find src/ -name *.cpp)
OUTPUT=bin/game
OBJS=$(subst .cpp,.o,$(SOURCES))
LDFLAGS=
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXX=g++
CXXFLAGS=-g

game: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(LDLIBS)

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(OUTPUT) $(OBJS)
