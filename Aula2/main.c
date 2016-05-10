#include <stdio.h>
#include "lista.h"

int main(){
	Lista pl;
	int i;

	inicLista(&pl);

	insereFim(&pl, 1);	
	insereFim(&pl, 3);
	insereOrdenado(&pl, 2);

	int tam = tamanho(&pl);

	exibe(&pl);

	//elem_t *e;
	//removeValor(&pl, 9);
	//ordena(&pl);
	//inverte(&pl);
	libera(&pl);

	printf("\n");

	exibe(&pl);

	return 0;
}