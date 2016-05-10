CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
LISTA = lista

ALL = main

all: $(ALL)

$(LISTA).o: $(LISTA).h $(LISTA).c

main: $(LISTA).o main.c

clean:
	rm -f *.o *~ $(ALL)

