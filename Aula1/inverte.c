#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vetor.h"

int main(){
	int n;
	int i;
	vet v;

	inicia(&v);	
	srand(time(NULL));
	for (i = 0; i < 20; i++){
		n = rand() % 100;
		printf("%d ", n);
		insere(&v, n);
	}

	printf("\n\n");
	while (!vazio(v)){
		retira(&v, &n);
		printf("%d ", n);
	}
	printf("\n\n");

	
	return 0;
}
