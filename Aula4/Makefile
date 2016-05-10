CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
PILHA = pilha

ALL = calcPos

all: $(ALL)

$(PILHA).o: $(PILHA).h $(PILHA).c

calcPos: $(PILHA).o calcPos.c

clean:
	rm -f *.o *~ $(ALL)
