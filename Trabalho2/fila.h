/*
 * Implementacao de Fila Dinâmica
 */

#ifndef FILA_H
#define FILA_H

typedef int elem_t;

typedef struct no{
  elem_t x;
  elem_t y;
  struct no *prox;
} No;

typedef struct fila{
	struct no *head;
	struct no *tail;
} Fila;

/* Inicializa uma Fila */
void inicFila(Fila *p_l);

/* Verifica se a Fila está vazia ou nao */
int filaVazia(Fila *p_l);

/* Verifica se a Fila está cheia ou nao */
int filaCheia(Fila *p_l);

/* Insere um elemento na Fila */
void insereFila(Fila *p_l, elem_t x, elem_t y);

/* Remove um elemento da Fila */
elem_t removeFila(Fila *p_l);

/* Remove todos os numeros da Fila */
void libera(Fila *p_l);

void exibeFila(Fila *p_l);

int tamanhoFila(Fila *p_l);

#endif
