#include "labirinto.h"
#include "pilha.h"
#include <stdio.h>

int linhas, colunas;

int inicLabirinto(Labirinto *l, char *arquivo){
	char *url, *nome, aux;
	int i , j = 0;
	FILE *arq;
	url = arquivo;
	nome = malloc(sizeof(char) * 40);

	arq = fopen(url, "r");

	if (arq != NULL){
		fscanf(arq, "%s", nome);
		fscanf(arq, "%d", &linhas);
		fscanf(arq, "%d", &colunas);
		fscanf(arq, "%c", &aux);

		l->p = (Posicao**) malloc (linhas * sizeof (Posicao *));
   		for (i = 0; i < linhas; i++)
      		l->p[i] = (Posicao*) malloc (colunas * sizeof (Posicao));

      	i = 0;
		while (!feof(arq)){
			fscanf(arq, "%c", &aux);
			if (aux != '\n'){
				l->p[i][j].tipo = aux;
				l->p[i][j].visitado = 0;
				j++;	
			}else{
				i++;
				j = 0;
			}
		}

	}else{
		printf("ERRO, não foi possivel abrir o arquivo\n");
	}

	fclose(arq);
}

void exibeLabirinto(Labirinto *l){
	int i, j;

	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf("%c ", l->p[i][j].tipo);
		}
		printf("\n");
	}
}

Fila* percorre(Labirinto *l){
	int i, j, flag = 0, count = 0, aux = 0;
	elem_t_pilha coord;
	Pilha p;

	for (i = 0; i < linhas && flag == 0; ++i)
		for (j = 0; j < colunas && flag == 0; ++j)
			if (l->p[i][j].tipo == 'o')
				flag = 1;

	i--; j--;

	l->p[i][j].visitado = 1;
	do{

		if (l->p[i][j - 1].tipo != 'x' && l->p[i][j - 1].tipo != 'b' && l->p[i][j - 1].visitado != 1){
			count++;
		}
		if (l->p[i][j + 1].tipo != 'x' && l->p[i][j + 1].tipo != 'b' && l->p[i][j + 1].visitado != 1){
			count++;	
		}
		if (l->p[i - 1][j].tipo != 'x' && l->p[i - 1][j].tipo != 'b' && l->p[i - 1][j].visitado != 1){
			count++;
		}
		if (l->p[i + 1][j].tipo != 'x' && l->p[i + 1][j].tipo != 'b' && l->p[i + 1][j].visitado != 1){
			count++;
		}

		if (count > 1){
			coord.x = i;
			coord.y = j;
			push(&p, coord);
		}

		count = 0;

		if (l->p[i][j - 1].tipo != 'x' && l->p[i][j - 1].tipo != 'b' && l->p[i][j - 1].visitado != 1){
			j--;
			l->p[i][j].visitado = 1;
		}else if (l->p[i][j + 1].tipo != 'x' && l->p[i][j + 1].tipo != 'b' && l->p[i][j + 1].visitado != 1){
			j++;
			l->p[i][j].visitado = 1;
		}else if (l->p[i - 1][j].tipo != 'x' && l->p[i - 1][j].tipo != 'b' && l->p[i - 1][j].visitado != 1){
			i--;
			l->p[i][j].visitado = 1;
		}else if (l->p[i + 1][j].tipo != 'x' && l->p[i + 1][j].tipo != 'b' && l->p[i + 1][j].visitado != 1){
			i++;
			l->p[i][j].visitado = 1;
		}else{
			coord = pop(&p);
			i = coord.x;
			j = coord.y;
			exibe(&p);
			if (PilhaVazia(&p)){
				printf("saiuu\n");
				break;
			}
		}

		//if (l->p[i][j].tipo == 'p')
			//printf("(%d , %d)\n", i, j);

		//printf("%d %d\n", i, j);
		aux++;
		
	}while (aux != 200);
	
}
