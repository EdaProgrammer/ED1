CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
VETORDIN = listaDin

ALL = main

all: $(ALL)

$(VETORDIN).o: $(VETORDIN).h $(VETORDIN).c

main: $(VETORDIN).o main.c

clean:
	rm -f *.o *~ $(ALL)

