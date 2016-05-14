CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
ED = labirinto

PILHA = pilha

FILA = fila

ALL = main

all: $(ALL)

$(ED).o: $(ED).h $(ED).c

$(PILHA).o: $(PILHA).h $(PILHA).c

$(FILA).o: $(FILA).h $(FILA).c

main: $(ED).o $(PILHA).o $(FILA).o main.c

clean:
	rm -f *.o *~ $(ALL)
