#include "calc-parser.h" // Importa le definizioni di tipi e le dichiarazioni
#include <stdio.h>       // Non necessario qui se l'hai messo nell'header, ma non fa male

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

    print_token_lookup();
}

// IMPLEMENTAZIONE della funzione di stampa per il DEBUG
void print_token_lookup() {
    printf("--- DEBUG TOKEN LOOKUP ---\n");
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (token_lookup[i] != TOKEN_UNKNOWN) {
            printf("Char '%c' (ASCII %d) -> Token ID: %d\n", i, i, token_lookup[i]);
        }
    }
    printf("--------------------------\n");
}
