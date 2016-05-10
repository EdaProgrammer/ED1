#include"vetor.h"

// Inicializa o vetor
void inicia (vet *v){
	v->tam = 0;
}

// Insere um elemento no final do vetor. Retorna 1 se a inserçao ocorreu com sucesso ou 0 caso contrario.
int insere (vet *v, elem_t n){
	if (!cheio(*v)){
		v->item[v->tam++] = n;
		return 1;
	}
	return 0;
}

// Remove um elemento do final do vetor. Retorna 1 se a remocao ocorreu com sucesso e 0 caso contrario
int retira (vet *v, elem_t *elemRemovido){
	if (!vazio(*v)){
		*elemRemovido = v->item[--v->tam];
		return 1; 
	}
	return 0;
}

// Verifica o numero de vezes que o elemento n se repete no vetor
int verRepeticao (vet v, elem_t n){
	int count = 0, i;
	for (i = 0; i < v.tam; i++)
		if (v.item[i] == n)
			count++;
	return count;
}

// Retorna 1 caso o vetor esteja cheio ou 0 caso contrario
int cheio (vet v){
	if (v.tam == MAX)
		return 1;
	return 0;
}

// Retorna 1 caso o vetor esteja vazio ou 0 caso contrario
int vazio (vet v){
	if (v.tam == 0)
		return 1;
	return 0;
}


// Retorna o elemento na posicao ind
elem_t acessa (vet v, int ind){
	return v.item[ind];
}

// Retorna o numero de elementos do vetor
int tamanho(vet v){
	return v.tam;
}

