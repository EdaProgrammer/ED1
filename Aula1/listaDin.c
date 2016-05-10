#include <stdlib.h>
#include "listaDin.h"

// Inicializa o vetor
void inicia (vet *v){
	v->item = 0;
	v->prox = NULL;
}

// Insere um elemento no inicio do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insereIni (vet *v, elem_t n){
	vet *novo;
	novo = (vet*)malloc(sizeof(vet));
	if(novo != NULL){	
		novo->item = n;
		novo->prox = v->prox;
		v->prox = novo;
		return 1;
	}
	return 0;
}


// Remove um elemento do inicio do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retiraIni (vet *v, elem_t *elemRemovido){
	vet *aux;

	if (!vazio(*v)){
		aux = v->prox;
		elemRemovido = aux->item;
		v->prox = aux->prox;
		free(aux);		
		return 1;
	}
	return 0;
}


// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n){
	vet *novo;

	novo = (vet*) malloc(sizeof(vet));
	if(novo != NULL){	
		novo->item = n;
		novo->prox = NULL;
	
		while(v->prox != NULL){
			v = v->prox;
		}
		v->prox = novo;
		return 1;
	}
	return 0;
}

// Remove um elemento do final do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retira (vet *v, elem_t *elemRemovido){
	vet *aux;
	if(!vazio(*v)){
		while(v->prox != NULL){
			aux = v;
			v = v->prox;
		}
		elemRemovido = v->item;
		aux->prox = NULL;
		free(v);	
		return 1;
		
	}
	return 0;
}

// Verifica o numero de vezes que o elemento n se repete no vetor
int verRepeticao (vet v, elem_t n){
	int count = 0;
	while(v.prox != NULL){
		v = *v.prox;
		if(v.item == n)
			count++;
		
	}
	return count;
}

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v){
	elem_t x = 0;
	if (insere(&v, x)){
		retira(&v, &x);
		return 0;
	}
	return 1;
}

// Retorna 1 caso o vetor esteja vazio ou 0 caso contrario
int vazio (vet v){
	if(v.prox == NULL)
		return 1;
	return 0;
}


// Retorna o elemento na posicao ind
elem_t acessa (vet v, int ind){
	int i = 0;
	for (i = 0; i < ind; i++){
		v = *v.prox;
	}
	return v.item;
}

// Retorna o numero de elementos do vetor
int tamanho(vet v){
	int count = 0;
	while (v.prox != NULL){
		v = *v.prox;
		count++;
	}
	return count;
}

