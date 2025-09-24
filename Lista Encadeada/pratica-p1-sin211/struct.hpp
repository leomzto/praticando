#ifndef STRUCT_HPP
#define STRUCT_HPP

// Simplesmente Encadeada:

typedef struct sNoS {
    int info;
    sNoS* prox;

    sNoS(int valor) : info(valor), prox(nullptr) {};
    
} NoS;

// Duplamente Encadeada:

typedef struct sNoD {
    sNoD* ant;
    int info;
    sNoD* prox;

    sNoD(int valor) : ant(nullptr), info(valor), prox(nullptr) {};

} NoD;

// Struct de uma Lista:

typedef struct sLista {
    NoS* inicioS;
    NoS* fimS;

    NoD* inicioD;
    NoD* fimD;

    int tamanho;

} Lista;


#endif