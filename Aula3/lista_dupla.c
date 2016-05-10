/*
 * Implementacao de lista dupla.
 */

#include"lista_dupla.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou nao */
int listaVazia(Lista *p_l){
	if (*p_l == NULL)
		return 1;
	return 0;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = malloc (sizeof(No_lista));
	novo->info = e;
	if (listaVazia(p_l)) {
		novo->prox = novo;
		novo->ant = novo;
	}
	else {
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant->prox = novo;
		(*p_l)->ant = novo;
	}
	*p_l = novo;	
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = malloc(sizeof(No_lista));
	novo->info = e;

	if (listaVazia(p_l)){
		*p_l = novo;
		novo->prox = novo;
		novo->ant = novo;
	}else{
		novo->prox = *p_l;
		novo->ant = (*p_l)->ant;
		(*p_l)->ant->prox = novo;
		(*p_l)->ant = novo;
	}
}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo, *aux;
	aux = *p_l;

	if (!ordenada(p_l)){
		ordena(p_l);
	}	
		novo = malloc (sizeof(No_lista));
		novo->info = e;
		if (listaVazia(p_l)){
			*p_l = novo;
			novo->prox = novo;
			novo->ant = novo;
		}else{
			if (aux->info > e){
				*p_l = novo;
				novo->prox = aux->prox;
				novo->ant = aux->ant;
			}
			aux = aux->prox;
			while (aux != *p_l && aux->info < e)
				aux = aux->prox;

			novo->prox = aux;
			novo->ant = aux->ant;
			aux->ant->prox = novo;
			aux->ant = novo;
		}
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	No_lista *aux;
	aux = *p_l;
	aux = aux->prox;
	while(aux != *p_l){
		if (aux->ant->info > aux->info)
			return 0;
		
		aux = aux->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	Lista atual = *p_l;
	Lista proximo = atual->prox;
	int inicio = 1;
	int i, j;
	int tam = tamanho(p_l);


	if (!listaVazia(p_l)){
		for (i = tam - 1; i >= 1; i--){
			for (j = 0; j < i; j++){
				if (atual->info >= proximo->info){
					if (inicio){
						*p_l = proximo;
						inicio = 0;
					}

					atual->ant->prox = proximo;
					proximo->ant = atual->ant;
					atual->ant = proximo;
					atual->prox = proximo->prox;
					proximo->prox->ant = atual;
					proximo->prox = atual;

					atual = proximo->prox;
					proximo = atual->prox;
				}else{
					atual = atual->prox;
					proximo = proximo->prox;
					inicio = 0;
				}
			}
			inicio = 1;
			atual = *p_l;
			proximo = atual->prox;
		}
	}
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;	

	if (listaVazia(p_l))
		return 0;

	if ((*p_l)->prox == *p_l){
		aux = *p_l;
		*p_l = NULL;
	}else{
		aux = *p_l;
		*p_l = aux->prox;
		(*p_l)->ant = aux->ant;
		aux->ant->prox = *p_l;
	}

	(*p_e) = aux->info;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	
	if (listaVazia(p_l)) return 0;
	
	if ((*p_l)->prox == *p_l)
	{
		aux = *p_l;
		*p_l = NULL;
	}
	
	else 
	{
		aux = (*p_l)->ant;
		(*p_l)->ant = aux->ant;
		aux->ant->prox = *p_l;
	}
	
	(*p_e) = aux->info;
	
	free(aux);
	return 1;
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero não tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	No_lista *aux, *lixo;
	aux = *p_l;
	int n;

	if (listaVazia(p_l))
		return 0;

	
	if (aux->info == e){
		removeInicio(p_l, &n);
		return 1;
	}

	aux = aux->prox;
	while (aux != *p_l){
		if (aux->info == e){
			lixo = aux;
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			free(lixo);
			return 1;
		}
		aux = aux->prox;
	}
	return 0;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *atual, *proximo;
	int tam, i;
	atual = *p_l;
	tam = tamanho(p_l);

	if (!listaVazia(p_l)){
		atual = atual->ant;

		*p_l = atual;
		proximo = atual->ant;
		for (i = 0; i < tam; i++){
			atual->ant = atual->prox;
			atual->prox = proximo;
			proximo = proximo->ant;
			atual = atual->prox;
		}
	}
}

int tamanho(Lista *p_l){
	No_lista *aux;
	aux = (*p_l)->prox;
	int count = 1;

	while (aux != *p_l){
		aux = aux->prox;
		count++;
	}

	return count;
}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	No_lista *aux, *lixo;
	aux = *p_l;

	if (!listaVazia(p_l)){
		aux = aux->prox;
		while (aux != *p_l){
			lixo = aux;
			aux = aux->prox;
			free(lixo);
		}
		*p_l = NULL;
	}
}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	Lista aux;
	aux = *p_l;
	if (!listaVazia(p_l)) {
		printf("%d ", aux->info);
		aux = aux->prox;
		while(aux != *p_l){
			printf("%d ", aux->info);
			aux = aux->prox;
		}
	}
}

