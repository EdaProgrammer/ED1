#include<stdio.h>
#include"fila.h"

int main(){
	Fila q;
	int i;
	inicFila(&q);
	
	for (i = 0; i < 9; i++)
		insereFila(&q, i);
		
	printf("Removeu %d\n", removeFila(&q));
	printf("Removeu %d\n", removeFila(&q));
	printf("Removeu %d\n", removeFila(&q));
	printf("Removeu %d\n", removeFila(&q));

	for (i = 10; i < 13; i++)
		insereFila(&q, i);
	printf("Removeu %d\n", removeFila(&q));
	
	furaFila(&q, 100);
	furaFila(&q, 200);
	
	while(!filaVazia(&q))
		printf("Removeu %d\n", removeFila(&q));
					
	return 0;
}
