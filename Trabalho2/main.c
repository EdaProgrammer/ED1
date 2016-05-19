#include <stdio.h>
#include "labirinto.h"

int main(){
	char *url = "labirinto.txt", *nome, aux;
	int i , j = 0, linhas, colunas, premios;
	Labirinto l;
	Fila f;
	FILE *arq;
	nome = malloc(sizeof(char) * 40);

	arq = fopen(url, "r");

	if (arq != NULL){
		fscanf(arq, "%s", nome);
		fscanf(arq, "%d", &linhas);
		fscanf(arq, "%d", &colunas);
		fscanf(arq, "%c", &aux);

		(&l)->p = (Posicao**) malloc (linhas * sizeof (Posicao *));
   		for (i = 0; i < linhas; i++)
      		(&l)->p[i] = (Posicao*) malloc (colunas * sizeof (Posicao));

      	i = 0;
		while (!feof(arq)){
			fscanf(arq, "%c", &aux);
			if (aux != '\n'){
				(&l)->p[i][j].tipo = aux;
				(&l)->p[i][j].visitado = 0;
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

	inicFila(&f);
	//exibeLabirinto(&l, linhas, colunas);
	f = percorre(&l, linhas, colunas);
	exibeFila(&f);

	premios = tamanhoFila(&f);
	printf("\nPremios encontrados: %d\n", premios);

	premios = 0;
	for (i = 0; i < linhas; ++i)
		for (j = 0; j < colunas; ++j)
			if ((&l)->p[i][j].tipo == 'p')
				premios++;

	printf("Total de premios no labirinto: %d\n", premios);

	return 0;
}