/*
 * Implementacao de Fila Circular
 */

#include"fila.h"

/* Inicializa uma Fila */
void inicFila(Fila *p_l){
	p_l->tam = 0;
	p_l->head = 0;
	p_l->tail = 0;	
}

/* Verifica se a Fila está vazia ou nao */
int filaVazia(Fila *p_l){
	if (p_l->tam == 0)
		return 1;
	return 0;
}

/* Verifica se a Fila está cheia ou nao */
int filaCheia(Fila *p_l){
	if (p_l->tam == MAX)
		return 1;
	return 0;
}

/* Insere um elemento na Fila */
void insereFila(Fila *p_l, elem_t_fila e){
	if (!filaCheia(p_l)){
		p_l->info[p_l->tail] = e;
		p_l->tail = (p_l->tail + 1) % MAX;
		p_l->tam++;
	}
}

/* Remove um elemento da Fila */
elem_t_fila removeFila(Fila *p_l){
	elem_t_fila aux;
	if (filaVazia(p_l))
		return -1;
	aux = p_l->info[p_l->head];
	p_l->head = (p_l->head + 1) % MAX;
	p_l->tam--;
	
	return 0;
}

/* Remove todos os numeros da Fila */
void liberaFila(Fila *p_l){
	inicFila(p_l);
}

/* Insere um elemento no inicio da Fila em O(1) */
void furaFila(Fila *p_l, elem_t_fila e){
	if (!filaCheia(p_l)){
		p_l->head = (p_l->head - 1) % MAX;
		p_l->info[p_l->tail] = e;
		p_l->tam++;
	}

}

