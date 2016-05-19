#ifndef labirinto
#define labirinto
#include "fila.h"

typedef struct posicao {
	char tipo;
	int visitado;
} Posicao;

typedef struct labirinto {
	Posicao **p;
} Labirinto;


void exibeLabirinto(Labirinto *l, int linhas, int colunas);

Fila percorre(Labirinto *l, int linhas, int colunas); // Retorna 1 se o vetor estiver cheio e 0 caso contrario


#endif