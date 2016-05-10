CC = gcc
CFLAGS = -g -Wall

# Coloque a implementação de vetor aqui...
ED = estoque

LC = listaCompras

ALL = main

all: $(ALL)

$(ED).o: $(ED).h $(ED).c

$(LC).o: $(LC).h $(LC).c

main: $(ED).o $(LC).o main.c

clean:
	rm -f *.o *~ $(ALL)
