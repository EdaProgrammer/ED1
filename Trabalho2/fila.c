#include <stdlib.h>
#include "fila.h"

/* Inicializa uma Fila */
void inicFila(Fila *p_l){
	p_l->head = NULL;
	p_l->tail = NULL;
}

/* Verifica se a Fila está vazia ou nao */
int filaVazia(Fila *p_l){
	if (p_l->head == NULL && p_l->tail == NULL)
		return 1;
	return 0;
}

/* Verifica se a Fila está cheia ou nao */
int filaCheia(Fila *p_l){
	return 0;
}

/* Insere um elemento na Fila */
void insereFila(Fila *p_l, elem_t x, elem_t y){
	No *novo;
	novo = malloc(sizeof(No));
	novo->x = x;
	novo->y = y;
	novo->prox = NULL;

	if(p_l->tail != NULL)
		p_l->tail->prox = novo;
	else
		p_l->head = novo;

	p_l->tail = novo;
}

void exibeFila(Fila *p_l) {
    No *aux;
    aux = p_l->head;
    while(aux != NULL){
        printf("(%d,%d) ", aux->x, aux->y);
        aux = aux->prox;
    }
}

int tamanhoFila(Fila *p_l){
	int count;
	No *aux;
	aux = p_l->head;
	while (aux != NULL){
		count++;
		aux = aux->prox;
	}

	return count;
}
