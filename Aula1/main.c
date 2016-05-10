#include <stdio.h>
#include <stdlib.h>
#include "listaDin.h"

int main(){
	vet v;
	int i;

	inicia(&v);
	
	for (i = 0; i < 10; i++)
		insere(&v, i);

	for (i = 1; i <= tamanho(v); i++)
		printf("%d ", acessa(v, i));

	elem_t *e = 0;
	retiraIni(&v, e);
	insere(&v, 1);
	printf("\n%d\n", verRepeticao(v, 1));

	for (i = 1; i <= tamanho(v); i++)
		printf("%d ", acessa(v, i));

	return 0;
}