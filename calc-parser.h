#ifndef CALC_PARSER_H
#define CALC_PARSER_H

#include <stdio.h>
#define ASCII_SIZE 128

//Token type
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

//Token
typedef struct {
	TokenType type; // ref to TokenType
	double value; //storage of numeric values
} Token;

//Token Array
typedef struct {
	Token tokens[100]; //ref to Token
	int count; //number of found tokens
} TokenArray;

extern TokenType token_lookup[ASCII_SIZE];
TokenArray tokenize(const char* input);
double evaluate(TokenArray*);

void print_token_lookup();
void token_lookup_init();
void print_token_array(const TokenArray* array);
void parse_opstr(const char* c);
#endif
