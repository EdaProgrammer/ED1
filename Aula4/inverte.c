#include"pilha.h"
#include<stdio.h>

int main(){
	Pilha s;
	char c;
	
	inicPilha(&s);
	scanf("%c",&c);
	while(c != '\n'){
		push(&s, c);
		scanf("%c",&c);
	}
	
	while(!PilhaVazia(&s)){
		printf("%c", pop(&s));
	}
	printf("\n");

	return 0;
}

