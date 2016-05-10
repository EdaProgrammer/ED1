#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCompras.h"


int criarListaDeCompra(LISTA_DE_COMPRA *lc){
    lc->inicio = NULL;
}

int inserirCompra(LISTA_DE_COMPRA *lc, char *nomeProd, int quantidade, ESTOQUE *e){

    int i, temEstoque = 0, temCompra = 0;
    float preco_item;

    for(i=0; i < e->tamanho; i++){
        if(strcmp(e->item[i].nome_prod, nomeProd) == 0){
            temEstoque = 1;
        }
    }

    if(temEstoque){
        NO_LISTA *novo, *aux, *anterior;
        ITEM item;

        novo = malloc(sizeof(NO_LISTA));
        anterior = NULL;

        novo->prod.nome_prod = nomeProd;
        novo->prox = NULL;
        item.nome_prod = nomeProd;
        item.qtdd = quantidade;

        for(i = 0; i < e->tamanho; i++){
            if(strcmp(e->item[i].nome_prod, nomeProd) == 0){
                novo->prod.preco = e->item[i].preco;
                if(e->item[i].qtdd <= quantidade){
                    item.qtdd = e->item[i].qtdd;
                    novo->prod.qtdd = e->item[i].qtdd;
                    quantidade = e->item[i].qtdd;
                    preco_item = quantidade * (e->item[i].preco);
                    lc->quantidade_itens += quantidade;
                    lc->total_preco += preco_item;
                }else{
                    novo->prod.qtdd = quantidade;
                    preco_item = quantidade * (e->item[i].preco);
                    lc->quantidade_itens += quantidade;
                    lc->total_preco += preco_item;
                }
            }
        }


        aux = lc->inicio;
        while(aux != NULL){
            if (strcmp(aux->prod.nome_prod, nomeProd) == 0){
                temCompra = 1;
                break;
            }
            aux = aux->prox;
        }

        if (!temCompra){
            if (lc->inicio == NULL){ 
                lc->inicio = novo;
                removerDoEstoque(e, item);
                return 1;
            }else{
                aux = lc->inicio;
                while(aux != NULL){
                    if(strcmp(novo->prod.nome_prod, aux->prod.nome_prod) < 0){
                        if (anterior == NULL){
                            lc->inicio = novo;
                        }else{
                            anterior->prox = novo;
                        }
                        novo->prox = aux;
                        removerDoEstoque(e, item);
                        return 1;
                    }
                    anterior = aux;
                    aux = aux->prox;
                }
                if (aux == NULL){
                    anterior->prox = novo;
                    novo->prox = NULL;
                    removerDoEstoque(e, item);
                    return 1;
                }
            }

        }else{
            aux->prod.qtdd += quantidade;
            removerDoEstoque(e, item);
            return 1;
        }
    }

    return 0;
}

int removerCompra(LISTA_DE_COMPRA *lc, ITEM *itemRemovido, ESTOQUE *e){
    int quantidade;
    NO_LISTA *aux, *anterior;
    anterior = NULL;

    aux = lc->inicio;

    while(aux != NULL){
        if(strcmp(itemRemovido->nome_prod,aux->prod.nome_prod) == 0){
            itemRemovido->preco = aux->prod.preco;
            quantidade = itemRemovido->qtdd * (-1);
            if(quantidade >= aux->prod.qtdd){
                if (anterior == NULL){
                    lc->inicio = lc->inicio->prox;
                }else{
                    anterior->prox = aux->prox;
                }
                lc->quantidade_itens -= aux->prod.qtdd;
                lc->total_preco -= aux->prod.qtdd * itemRemovido->preco;
                itemRemovido->qtdd = aux->prod.qtdd;
                inserirNoEstoque(e, *itemRemovido);
                free(aux);
                return 1;
            }else{
                aux->prod.qtdd -= quantidade;
                lc->quantidade_itens -= quantidade;
                lc->total_preco -= quantidade * itemRemovido->preco;
                itemRemovido->qtdd = quantidade;
                inserirNoEstoque(e, *itemRemovido);
                return 1;
            }

        }
        anterior = aux;
        aux = aux->prox;
    }


    return 0;
}

int removerProdutos(LISTA_DE_COMPRA *lc){
    lc->inicio = NULL;
    lc->quantidade_itens = 0;
    lc->total_preco = 0;

    return 1;

}

void imprimeCompra(LISTA_DE_COMPRA *lc){
    NO_LISTA *aux;
    float total_parcial;

    aux = lc->inicio;
    while(aux != NULL){
        total_parcial = aux->prod.qtdd * aux->prod.preco;
        printf("\n %s\t %d x %.2f = %.2f", aux->prod.nome_prod, aux->prod.qtdd, aux->prod.preco, total_parcial);
        aux = aux->prox;
    }
    printf("\n Número de itens: %d \n Total a ser pago: R$ %.2f\n\n", lc->quantidade_itens, lc->total_preco);


}
