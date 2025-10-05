#include <stdio.h>
#include "calc-parser.h"


int main(void){

	char opstr[100];
	printf("Inserisci l'operazione\n");
	
	fgets(opstr, 100, stdin);

	token_lookup_init();
	parse_opstr(opstr);

	printf("%s", opstr);
	return 0;
}

