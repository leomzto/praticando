#include <bits/stdc++.h>

using namespace std;

#ifndef LSE_H
#define LSE_H

typedef struct sNo
{
    int info;
    sNo* prox;

    sNo(int valor) : info(valor), prox(nullptr) {}
} No;

typedef struct sLista
{
    No* inicio;
    No* fim;

    sLista() : inicio(nullptr), fim(nullptr) {}
} Lista;

No* criarNo(int valor);
void liberarNo(No* no);

void liberarLista(Lista* lista);

bool listaVazia(Lista* lista);

void inserirInicio(Lista* lista, int valor);
void inserirFim(Lista* lista, int valor);

void removerInicio(Lista* lista);
void removerFim(Lista* lista);

void imprimirLista(Lista* lista);

Lista* copiarLista(Lista* l1);
Lista* concatenarListas(Lista* l1, Lista* l2);
Lista* inverterLista(Lista* lista);
void removerRepetidos(Lista* lista);
void ordenarLista(Lista* lista);
Lista* dividirLista(Lista* lista, int posN);
bool listasIguais(Lista* l1, Lista* l2);


// Lista Estatica
#define MAX 100
typedef struct sVLista
{
    int tamanho;
    int dados[MAX];
} vLista;

Lista* encadearVetor(vLista* lista_v);
vLista* vetoriarListaEncadeada(Lista* lista);


#endif