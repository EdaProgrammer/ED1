#include <stdio.h>
#include "lista.h"

void inicLista(Lista *p_l){
	*p_l = NULL;
}

int listaVazia(Lista *p_l){
	if (*p_l == NULL){
		return 1;
	}
	return 0;
}

void insereInicio(Lista *p_l, elem_t e){
	Lista novo;
	Lista aux = *p_l;
	novo = (Lista*) malloc (sizeof(Lista));

	if (novo != NULL){
		novo->info = e;
		novo->prox = aux;
		*p_l = novo;
	}
}

void insereFim(Lista *p_l, elem_t e){
	Lista novo;
	Lista aux = *p_l;
	novo = (Lista*) malloc (sizeof(Lista));

	if (novo != NULL){
		if (aux == NULL){
			novo->info = e;
			novo->prox = NULL;
			*p_l = novo;	
		}else{
			while (aux->prox != NULL){
				aux = aux->prox;
			}
			novo->info = e;
			novo->prox = NULL;
			aux->prox = novo;	
		}
	}
}

void insereOrdenado(Lista *p_l, elem_t e){
	Lista novo;
	Lista aux = *p_l;
	if (ordenada(p_l)){  
		novo = (Lista*) malloc (sizeof(Lista));
		if (aux == NULL || (aux != NULL && aux->info > e)){
			novo->info = e;
			novo->prox = aux;
			*p_l = novo;
		}else{
			while (aux->prox != NULL && aux->prox->info < e)
				aux = aux->prox;

			novo->info = e;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
}


int ordenada(Lista *p_l){
	Lista aux = *p_l;
	while (aux->prox != NULL){
		if (aux->info > aux->prox->info){
			return 0;
		}
		aux = aux->prox;
	}
	return 1;
}

void ordena(Lista *p_l){
	Lista atual = *p_l;
	Lista proximo = atual->prox;
	Lista anterior = NULL;
	int i, j;
	int tam = tamanho(p_l);


	for (i = tam - 1; i >= 1; i--){
		for (j = 0; j < i; j++){
			if (atual->info > proximo->info){
				if (anterior != NULL){
					anterior->prox = atual->prox;
				}else{
					*p_l = proximo;
				}
				atual->prox = proximo->prox;
				proximo->prox = atual;

				anterior = proximo;
				atual = anterior->prox;
				proximo = atual->prox;
			}else{
				anterior = atual;
				atual = atual->prox;
				proximo = proximo->prox;
			}
		}
		anterior = NULL;
		atual = *p_l;
		proximo = atual->prox;
	}
}

int removeInicio(Lista *p_l, elem_t *p_e){
	Lista aux = *p_l;
	if (aux != NULL){
		p_e = aux->info;
		*p_l = (*p_l)->prox;
		free(aux);
		return 1;
	}
	return 0;

}

int removeFim(Lista *p_l, elem_t *p_e){
	Lista aux = *p_l;
	Lista penultimo = aux;
	if (aux != NULL){
		while (aux->prox != NULL){
			penultimo = aux;
			aux = aux->prox;
		}
		p_e = aux->info;
		penultimo->prox = NULL;
		free(aux);
		return 1;
	}	
	return 0;
}

int removeValor(Lista *p_l, elem_t e){
	Lista aux = *p_l;
	Lista penultimo = aux;
	elem_t *el;
	int inicio = 0;
	if (aux != NULL){
		while (aux != NULL){
			if (aux->info == e){
				if (inicio != 0){
					penultimo->prox = aux->prox;
					free(aux);	
				}else
					removeInicio(p_l, el);
			}
			penultimo = aux;
			aux = aux->prox;
			inicio++;
		}
	}
}

void inverte(Lista *p_l){
	Lista anterior, atual, proximo;
	anterior = NULL;
	atual = *p_l;
	while (atual != NULL){
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = proximo;
	}
	*p_l = anterior;
}

int tamanho(Lista *p_l){
	int count = 0;
	Lista aux = *p_l;
	while (aux != NULL){
		count++;
		aux = aux->prox;
	}

	return count;
}

void libera(Lista *p_l){
	Lista aux = *p_l;
	Lista lixo;
	while (aux != NULL){
		lixo = aux;
		aux = aux->prox;
		free(lixo);
	}
	*p_l = NULL;
}

void exibe(Lista *p_l){
	Lista aux;
	aux = *p_l;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}