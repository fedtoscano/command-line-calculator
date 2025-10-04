#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <stdio.h>

#define ASCII_SIZE 128

typedef enum{
	TOKEN_UNKNOWN = 0,
    	TOKEN_NUM,
    	TOKEN_ADD,
    	TOKEN_SOTTR,
    	TOKEN_MOLT,
    	TOKEN_DIV,
    	TOKEN_OPEN_ROUND_BR,
    	TOKEN_CLOSED_ROUND_BR,
    	TOKEN_OPEN_SQUARE_BR,
    	TOKEN_CLOSED_SQUARE_BR,
    	TOKEN_OPEN_CURLY_BR,
    	TOKEN_CLOSED_CURLY_BR
} TokenType;

extern TokenType token_lookup[ASCII_SIZE];

void print_token_lookup();
void token_lookup_init();

#endif
