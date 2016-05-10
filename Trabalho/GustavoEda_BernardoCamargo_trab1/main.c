#include <stdio.h>
#include <string.h>
#include "estoque.h"
#include "listaCompras.h"

int main(){
	ESTOQUE e;
	LISTA_DE_COMPRA lc;
	char c;
	int qtd;
	criarListaDeEstoque(&e);
	criarListaDeCompra(&lc);

	do{
		printf("\nDeseja iniciar uma nova compra? (S/N)");
		__fpurge(stdin);
		scanf("%c", &c);
		do{
			if (c == 'S' || c == 's'){
	 			scanf("%d", &qtd);

	 			if (qtd == 0){
	 				imprimeCompra(&lc);
	 				removerProdutos(&lc);
	 				break;
	 			}

	 			char *prod = malloc(sizeof(char) * 40);
	 			scanf("%s", prod);

	 			if (qtd > 0){
	 				inserirCompra(&lc, prod, qtd, &e);
	 			}else if (qtd < 0){
	 				ITEM rem;
	 				rem.nome_prod = prod;
	 				rem.qtdd = qtd;
	 				removerCompra(&lc, &rem, &e);
	 			}

			}else
				break;
		}while (qtd != 0);
		if (c == 'N' || c == 'n')
			return 0;

	}while (c != 'S' || c != 's');

	return 0;
}