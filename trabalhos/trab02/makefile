CC=g++
CFLAGS=-Wall

PROGRAM=trab02
OBJS=main.o vertice.o aresta.o grafo.o

all: $(PROGRAM)

exec: $(PROGRAM)
	./$(PROGRAM)

execlean: $(PROGRAM) clean
	./$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(OBJS)

clean-all:
	rm -vf $(OBJS) $(PROGRAM) *.out
