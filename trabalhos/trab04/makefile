CC=g++
CFLAGS=-Wall -std=c++11

PROGRAM=trab04
OBJS=main.o cadastro.o paciente.o phospitalar.o arvore.o

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
