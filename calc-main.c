#include <stdio.h>
#include "calc-parser.h"


int main(void){

	char opstr[100];
	printf("Inserisci l'operazione\n");
	
	fgets(opstr, 100, stdin);

	token_lookup_init();
	

	TokenArray tokens = tokenize(opstr);
	print_token_array(&tokens);

	return 0;
}

