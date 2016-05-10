#include <stdio.h>
#include <string.h>
#include "estoque.h"

int criarListaDeEstoque(ESTOQUE *e){
	char	url[] = "mercadorias.txt";
	float 	preco;
	int 	qtd, opcao, i;
	FILE 	*arq;
	ITEM 	novo, lixo;

	e->tamanho = 0;
	arq = fopen(url, "r");

	if (arq != NULL){
		while (!feof(arq)){
			fscanf(arq, "%d", &opcao);
			if (opcao == 1){
				char *nome = malloc(sizeof(char) * 40);
				fscanf(arq, "%s %f %d\n", nome, &preco, &qtd);
				novo.nome_prod = nome;
				novo.preco = preco;
				novo.qtdd = qtd;
				inserirNoEstoque(e, novo);
			}else if (opcao == 2){
				char *nomeLixo = malloc(sizeof(char) * 40);
				fscanf(arq, "%s %d\n", nomeLixo, &qtd);
				lixo.nome_prod = nomeLixo;
				lixo.qtdd = qtd;
				removerDoEstoque(e, lixo);
			}
		}
	}else{
		printf("ERRO, não foi possivel abrir o arquivo\n");
	}
	fclose(arq);
	return 0;
}

int inserirNoEstoque(ESTOQUE *e, ITEM prod){
	int i, temEstoque = 0;
	for(i= 0; i < e->tamanho; i++){
    	if(strcmp(e->item[i].nome_prod, prod.nome_prod) == 0){
        	temEstoque = 1;
        	break;
        }
    }

	if (!estoqueCheio(e)){
		if (!temEstoque){
			e->item[e->tamanho] = prod;
			e->tamanho++;
			return 1;
		}else{
            e->item[i].qtdd += prod.qtdd;
            return 1;
        }
    }
return 0;
}

int removerDoEstoque(ESTOQUE *e, ITEM itemRemovido){
	int i, j;

	for (i = 0; i < e->tamanho; i++){
		if (strcmp(e->item[i].nome_prod, itemRemovido.nome_prod) == 0){
			e->item[i].qtdd -= itemRemovido.qtdd;
			if (e->item[i].qtdd <= 0){
				for (j = i; j < e->tamanho - 1; j++){
					e->item[j] = e->item[j + 1];
				}
				e->tamanho--;
			}
			return 1;
		}
	}
	return 0;
}

int estoqueCheio(ESTOQUE *e){
	if (e->tamanho == MAX)
		return 1;
	return 0;
}

int estoqueVazio(ESTOQUE *e){
	if (e->tamanho == 0)
		return 1;
	return 0;
}

void listar(ESTOQUE *e){
	int i;
	
	for (i = 0; i < e->tamanho; i++){
		printf("%s %.2f %d\n",e->item[i].nome_prod, e->item[i].preco, e->item[i].qtdd);
	}
}

