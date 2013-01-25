SOURCES=$(shell find ./ -name src/*.cpp)
OUTPUT=bin/game
OBJS=$(subst .cpp,.o,$(SOURCES))

game: $(OBJS)
	g++ $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(LDLIBS)

%.o: %.cpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm $(OUTPUT) $(OBJS)
