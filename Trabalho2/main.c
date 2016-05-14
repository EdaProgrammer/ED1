#include <stdio.h>
#include "labirinto.h"

int main(){
	char *url = "labirinto.txt";
	Labirinto l;

	inicLabirinto(&l, url);
	exibeLabirinto(&l);
	percorre(&l);

	return 0;
}