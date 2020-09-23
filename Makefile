OBJECTS=main.o funcs.o
CXXFLAGS=-Wall
LDFLAGS=-lm

main: $(OBJECTS)
	g++ $(LDFLAGS) -o main $(OBJECTS)

main.o: main.cpp funcs.h
	g++ -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

clean:
	rm -f $(OBJECTS) main
