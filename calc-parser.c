#include "calc-parser.h" 
#include <stdio.h>
#include <stdlib.h>

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


TokenArray tokenize(const char* input){
    TokenArray token_array = {0};

    while(*input != '\0'){
        if(*input == ' ' || *input == '\n'){
            input++;
            continue;
        }

        //check TokenType
        TokenType type = token_lookup[(unsigned char) *input];

        //if number
        if(type == TOKEN_NUM){
            token_array.tokens[token_array.count].type = TOKEN_NUM;
            token_array.tokens[token_array.count].value = strtod(input, (char**)&input);
            token_array.count++;
            continue;
        }

        //if operator or bracket
        if(type != TOKEN_UNKNOWN){
            token_array.tokens[token_array.count].type = type;
            token_array.tokens[token_array.count].value = 0;
            token_array.count++;
        }

        input++;
    }

    return token_array;
}

double evaluate(TokenArray* tokens){}


//Prints the TokenArray (debug method)
void print_token_array(const TokenArray* array) {
    printf("\n=== Token Array Contents ===\n");
    for (int i = 0; i < array->count; i++) {
        printf("Token[%d]: ", i);
        switch (array->tokens[i].type) {
            case TOKEN_NUM:
                printf("NUMBER (%.2f)\n", array->tokens[i].value);
                break;
            case TOKEN_ADD:
                printf("OPERATOR (+)\n");
                break;
            case TOKEN_SOTTR:
                printf("OPERATOR (-)\n");
                break;
            case TOKEN_MOLT:
                printf("OPERATOR (*)\n");
                break;
            case TOKEN_DIV:
                printf("OPERATOR (/)\n");
                break;
            case TOKEN_OPEN_ROUND_BR:
                printf("BRACKET ()\n");
                break;
            case TOKEN_CLOSED_ROUND_BR:
                printf("BRACKET ()\n");
                break;
            default:
                printf("UNKNOWN\n");
        }
    }
    printf("=========================\n");
}