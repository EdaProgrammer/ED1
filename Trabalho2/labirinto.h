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


int inicLabirinto(Labirinto *l, char *arquivo); // Retorna 1 se iniciar com sucesso

void exibeLabirinto(Labirinto *l);

Fila* percorre(Labirinto *l); // Retorna 1 se o vetor estiver cheio e 0 caso contrario


#endif