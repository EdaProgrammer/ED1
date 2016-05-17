/*
 * 
 */

#ifndef PILHA_H
#define PILHA_H

typedef struct coord{
	int x, y;
} elem_t_pilha;

typedef struct noPilha{
  elem_t_pilha info;
  struct noPilha *prox;
} No_Pilha;

typedef No_Pilha Pilha;

/* Inicializa uma Pilha */
void inicPilha(Pilha *p_l);

/* Verifica se a Pilha está vazia ou nao */
int PilhaVazia(Pilha *p_l);

/* Insere um elemento na Pilha */
void push(Pilha *p_l, elem_t_pilha e);

/* Remove um elemento da Pilha */
elem_t_pilha pop(Pilha *p_l);

/* Retorna o elemento do topo da pilha */
elem_t_pilha elemTopo(Pilha *p_l);

/* Remove todos os numeros da Pilha */
void liberaPilha(Pilha *p_l);

/* Exibe o conteudo da Pilha */
void exibe(Pilha *p_l);

#endif
