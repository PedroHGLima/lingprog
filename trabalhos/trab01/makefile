CC=g++
CLFAGS=-Wall

PROGRAM = trab01
OBJECTS = estadual.o nacional.o

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) main.cpp $(OBJECTS) -o $(PROGRAM).exe

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(OBJECTS)

clean-all:
	rm -vf $(OBJECTS) $(PROGRAM).exe
