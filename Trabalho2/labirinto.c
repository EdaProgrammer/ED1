#include "labirinto.h"
#include "pilha.h"
#include <stdio.h>


void exibeLabirinto(Labirinto *l, int linhas, int colunas){
	int i, j;

	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf("%c ", l->p[i][j].tipo);
		}
		printf("\n");
	}
}

Fila percorre(Labirinto *l, int linhas, int colunas){
	int i, j, flag = 0, count = 0;
	elem_t_pilha coord;
	Pilha p;
	Fila f;

    inicFila(&f);
	inicPilha(&p);

	for (i = 0; i < linhas && flag == 0; ++i)
		for (j = 0; j < colunas && flag == 0; ++j)
			if (l->p[i][j].tipo == 'o')
				flag = 1;

	i--; j--;

	l->p[i][j].visitado = 1;
	do{

		if (l->p[i][j - 1].tipo != 'x' && l->p[i][j - 1].tipo != 'b' && l->p[i][j - 1].visitado == 0)
			count++;
		if (l->p[i][j + 1].tipo != 'x' && l->p[i][j + 1].tipo != 'b' && l->p[i][j + 1].visitado == 0)
			count++;	
		if (l->p[i - 1][j].tipo != 'x' && l->p[i - 1][j].tipo != 'b' && l->p[i - 1][j].visitado == 0)
			count++;
		if (l->p[i + 1][j].tipo != 'x' && l->p[i + 1][j].tipo != 'b' && l->p[i + 1][j].visitado == 0)
			count++;

		if (count > 1){
			coord.x = i;
			coord.y = j;
			push(&p, coord);
		}

		count = 0;

		if (l->p[i][j - 1].tipo != 'x' && l->p[i][j - 1].tipo != 'b' && l->p[i][j - 1].visitado == 0){
			j--;
		}else if (l->p[i][j + 1].tipo != 'x' && l->p[i][j + 1].tipo != 'b' && l->p[i][j + 1].visitado == 0){
			j++;
		}else if (l->p[i - 1][j].tipo != 'x' && l->p[i - 1][j].tipo != 'b' && l->p[i - 1][j].visitado == 0){
			i--;
		}else if (l->p[i + 1][j].tipo != 'x' && l->p[i + 1][j].tipo != 'b' && l->p[i + 1][j].visitado == 0){
			i++;
		}else{
			coord = pop(&p);
			i = coord.x;
			j = coord.y;
			if (PilhaVazia(&p))
				break;
		}

		l->p[i][j].visitado++;

		if (l->p[i][j].tipo == 'p' && l->p[i][j].visitado == 1){
			insereFila(&f, i, j);
		}
		
	}while (1);

	return f;		
	
}
