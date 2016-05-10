#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "pilha.h"

int main(){
	char expressao[40], pos[40], aux;
	int tam, i, j = 0;
	Pilha stack;
	inicPilha(&stack);

	printf("Digite a expressão algebrica\n");
	scanf("%s", expressao);

	tam = strlen(expressao);
	for (i = 0; i < tam; i++){
		switch(expressao[i]){
			case '(':
				push(&stack, expressao[i]);
				break;
			case ')':
				aux = pop(&stack);
				while (aux != '('){
					pos[j++] = aux;
					aux = pop(&stack);
				}
				break;

			case '+':
			case '-':
				aux = pop(&stack);
				while (aux != '('){
					pos[j++] = aux;
					aux = pop(&stack);
				}
				push(&stack, aux);
				push(&stack, expressao[i]);
				break;

			case '*':
			case '/':
				aux = pop(&stack);
				while (aux != '(' && aux != '+' && aux != '-'){
					pos[j++] = aux;
					aux = pop(&stack);
				}
				push(&stack, aux);
				push(&stack, expressao[i]);
				break;

			default :
				pos[j++] = expressao[i];
		}
	}
	pos[j++] = '\0';
	printf("%s\n", pos);
	libera(&stack);

	int result;
	tam = strlen(pos);
	for (i = 0; i < tam; i++){
		switch(pos[i]){
			case '+':
				result = pop(&stack) - '0';
				result += pop(&stack) - '0';
				aux = result + '0';
				push(&stack, aux);
				break;
			case '-':
				result = pop(&stack) - '0';
				result = pop(&stack) - '0' - result;
				aux = result + '0';
				push(&stack, aux);
				break;
			case '*':
				result = pop(&stack) - '0';
				result *= pop(&stack) - '0';
				aux = result + '0';
				push(&stack, aux);
				break;

			case '/':
				result = pop(&stack) - '0';
				result = pop(&stack) - '0' / result;
				aux = result + '0';
				push(&stack, aux);
				break;

			default :
				push(&stack, pos[i]);
		}
	}
	result = pop(&stack) - '0';

	printf("%d\n", result);
}