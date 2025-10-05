#include "calc-parser.h" 
#include <stdio.h>

TokenType token_lookup[ASCII_SIZE] = {TOKEN_UNKNOWN};


void token_lookup_init() {
    token_lookup['+'] = TOKEN_ADD;
    token_lookup['-'] = TOKEN_SOTTR;
    token_lookup['*'] = TOKEN_MOLT;
    token_lookup['/'] = TOKEN_DIV;

    for (int i = 0; i <= 9; i++) {
        token_lookup['0' + i] = TOKEN_NUM;
    }
    token_lookup['('] = TOKEN_OPEN_ROUND_BR;
    token_lookup[')'] = TOKEN_CLOSED_ROUND_BR;

    //print_token_lookup();
}

void print_token_lookup() {
    printf("--- DEBUG TOKEN LOOKUP ---\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (token_lookup[i] != TOKEN_UNKNOWN) {
            printf("Char '%c' (ASCII %d) -> Token ID: %d\n", i, i, token_lookup[i]);
        }
    }
    printf("--------------------------\n");
}


void parse_opstr(const char *str){
    while(*str != '\0'){
        TokenType token = token_lookup[(unsigned char) *str];
        if(token != TOKEN_UNKNOWN && *str != ' ' && *str != '\n')
            printf("Token: %d for char: %c\n", token, str);
        str++;
    }
	printf("%c", str);
}

TokenArray tokenize(const char* input){}
