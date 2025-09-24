#include <bits/stdc++.h>

using namespace std;

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

No* alocarNo(int valor)
{
    return new No(valor);
}

void liberarNo(No* no)
{
    delete no;
}

void liberarLista(Lista* l)
{
    No* posAtual = l->inicio;

    while (posAtual != nullptr)
    {
        No* prox = posAtual->prox;
        delete posAtual;
        posAtual = prox;
    }

    l->inicio = l->fim = nullptr;
}

bool listaVazia(Lista* l)
{
    return l->inicio == nullptr;
}

void inserirNoInicio(Lista* l, int valor)
{
    No* novoNo = alocarNo(valor);

    novoNo->prox = l->inicio;
    l->inicio = novoNo;

    if (l->fim == nullptr)
        l->fim = novoNo;
}

void inserirNoFim(Lista* l, int valor)
{
    No* novoNo = alocarNo(valor);

    if (listaVazia(l))
    {    
        l->inicio = novoNo;
        l->fim = novoNo;
    }
    else
    {    
        l->fim->prox = novoNo;
        l->fim = novoNo;
    }
}

void removerDoInicio(Lista* l)
{
    if (listaVazia(l)) return;

    No* antigoNo = l->inicio;

    l->inicio = l->inicio->prox;

    if (l->inicio == nullptr)
        l->fim = nullptr;

    delete antigoNo;
}

void removerDoFim(Lista* l)
{
    if (listaVazia(l)) return;

    if (l->inicio == l->fim)
    {
        liberarLista(l);
        return;
    }

    No* posAtual = l->inicio;

    while (posAtual->prox != nullptr)
        posAtual = posAtual->prox;

    delete l->fim;
    posAtual->prox = nullptr;
    l->fim = posAtual;
}

void removerValor(Lista* l, int valor)
{
    if (listaVazia(l)) return;

    if (valor == l->inicio->info)
    {
        removerDoInicio(l);
        return;
    }

    if (valor == l->fim->info)
    {
        removerDoFim(l);
        return;
    }

    No* posAnterior = l->inicio;
    No* posAtual = l->inicio->prox;

    while (posAtual != nullptr)
    {
        if (posAtual->info == valor)
        {
            posAnterior->prox = posAtual->prox;
            delete posAtual;
            return;
        }

        posAnterior = posAtual;
        posAtual = posAtual->prox;
    }
}

Lista* copiarLista(Lista* l)
{
    Lista* copia = new Lista();

    No* posAtual = l->inicio;

    while (posAtual != nullptr)
    {
        inserirNoFim(copia, posAtual->info);
        posAtual = posAtual->prox;
    }

    return copia;   
}

void ordenarLista(Lista* l)
{
    if (listaVazia(l)) return;

    bool trocou;
    do 
    {
        trocou = false;
        No* posAtual = l->inicio;

        while (posAtual->prox != nullptr)
        {
            if (posAtual->info == posAtual->prox->info)
            {
                swap(posAtual->info, posAtual->prox->info);
                trocou = true;
            }

            posAtual = posAtual->prox;
        }
    } while (trocou);
}

bool listasIguais(Lista* l1, Lista* l2)
{
    No* posAtual1 = l1->inicio;
    No* posAtual2 = l2->inicio;

    while (posAtual1 != nullptr && posAtual2 != nullptr)
    {
        if (posAtual1->info != posAtual2->info)
            return false;
        
        posAtual1 = posAtual1->prox;
        posAtual2 = posAtual2->prox;
    }

    if (posAtual1 != nullptr || posAtual2 != nullptr)
        return false;

    return true;
}