#include "lse.h"

No* criarNo(int valor)
{
    return new No(valor);
}

void liberarNo(No* no)
{
    delete no;
}

void liberarLista(Lista* lista)
{
    No* posAtual = lista->inicio;

    while(posAtual != nullptr)
    {
        No* prox = posAtual->prox;
        delete posAtual;
        posAtual = prox;
    }

    lista->inicio = nullptr;
    lista->fim = nullptr;
}

bool listaVazia(Lista* lista)
{
    return lista->inicio == nullptr;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);

    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;

    if (lista->fim == nullptr)
        lista->fim = novoNo;
}

void inserirFim(Lista* lista, int valor)
{
    No* novoNo = criarNo(valor);

    if (lista->inicio == nullptr)
    {
        lista->inicio = novoNo;
        lista->fim = novoNo;
    }
    else
    {
        lista->fim->prox = novoNo;
        lista->fim = novoNo;
    }
}

void removerInicio(Lista* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

    No* excluir = lista->inicio;

    lista->inicio = lista->inicio->prox;

    if (lista->inicio == nullptr)
        lista->fim = nullptr;
    delete excluir;
}

void removerFim(Lista* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

    if (lista->inicio == lista->fim)
    {
        liberarLista(lista);
        return;
    }

    No* posAtual = lista->inicio;

    while(posAtual->prox != lista->fim)
        posAtual = posAtual->prox;

    delete lista->fim;
    posAtual->prox = nullptr;
    lista->fim = posAtual;
}

void imprimirLista(Lista* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }
    
    No* posAtual = lista->inicio;

    while(posAtual != nullptr)
    {
        cout << posAtual->info << " -> ";
        posAtual = posAtual->prox;
    }

    cout << "NULL" << endl;
}

Lista* copiarLista(Lista* l1)
{
    Lista* l2 = new Lista();

    No* posAtualL1 = l1->inicio;
    
    while (posAtualL1 != nullptr)
    {
        No* novoNo = criarNo(posAtualL1->info);
        
        if (listaVazia(l2))
        {
            l2->inicio = novoNo;
            l2->fim = novoNo;
        }
        else
        {
            l2->fim->prox = novoNo;
            l2->fim = novoNo;
        }

        posAtualL1 = posAtualL1->prox;
    }

    return l2;
}

Lista* concatenarListas(Lista* l1, Lista* l2)
{
    Lista* concatenadas = new Lista();

    No* posAtual = l1->inicio;
    while (posAtual != nullptr)
    {
        inserirFim(concatenadas, posAtual->info);
        posAtual = posAtual->prox;
    }

    posAtual = l2->inicio;
    while (posAtual != nullptr)
    {
        inserirFim(concatenadas, posAtual->info);
        posAtual = posAtual->prox;
    }

    return concatenadas;
}

Lista* inverterLista(Lista* lista)
{
    Lista* invertida = new Lista();

    No* posAtual = lista->inicio;

    while (posAtual != nullptr)
    {
        inserirInicio(invertida, posAtual->info);
        posAtual = posAtual->prox;
    }

    return invertida;
}

void removerRepetidos(Lista* lista)
{
    Lista* novaLista = new Lista();

    No* posAtual = lista->inicio;

    while (posAtual != nullptr)
    {
        bool existe = false;

        No* temp = novaLista->inicio;
        while (temp != nullptr)
        {
            if (temp->info == posAtual->info)
            {
                existe = true;
                break;
            }
            temp = temp->prox;
        }

        if (!existe)
            inserirFim(novaLista, posAtual->info);

        posAtual = posAtual->prox;
    }

    liberarLista(lista);

    lista->inicio = novaLista->inicio;
    lista->fim = novaLista->fim;

    delete novaLista;
}

void ordenarLista(Lista* lista)
{
    if (listaVazia(lista) || lista->inicio->prox == nullptr) return;

    bool trocou;

    do
    {
        trocou = false;
        No* posAtual = lista->inicio;

        while (posAtual->prox != nullptr)
        {
            if (posAtual->info > posAtual->prox->info)
            {
                int aux = posAtual->info;
                posAtual->info = posAtual->prox->info;
                posAtual->prox->info = aux;
                trocou = true;
            }
            posAtual = posAtual->prox;
        }
    } while (trocou);
}

Lista* dividirLista(Lista* lista, int posN)
{
    Lista* novaLista = new Lista();

    if (listaVazia(lista) || posN <= 0) return novaLista;

    No* posAtual = lista->inicio;
    int cont = 1;

    while (posAtual->prox != nullptr && cont < posN)
    {
        posAtual = posAtual->prox;
        cont++;
    }

    if (posAtual->prox == nullptr)
        return novaLista;

    novaLista->inicio = posAtual->prox;

    No* temp = novaLista->inicio;
    while (temp->prox != nullptr)
        temp = temp->prox;
    novaLista->fim = temp;

    posAtual->prox = nullptr;
    lista->fim = posAtual;

    return novaLista;
}

bool listasIguais(Lista* l1, Lista* l2)
{
    if (listaVazia(l1) || listaVazia(l2)) return false;

    No* atualL1 = l1->inicio;
    No* atualL2 = l2->inicio;

    while (atualL1 != nullptr && atualL2 != nullptr)
    {
        if (atualL1->info != atualL2->info)
            return false;
            
        atualL1 = atualL1->prox;
        atualL2 = atualL2->prox;
    }

    if (atualL1 != nullptr || atualL2 != nullptr)
        return false;

    return true;
}

// Listas Estaticas
Lista* encadearVetor(vLista* lista_v)
{
    lista_v->tamanho = 0;

    int tamanho_teste = 10;
    for(int i = 0; i < tamanho_teste; i++)
    {
        lista_v->dados[i] = rand() % 10;
        lista_v->tamanho++;
    }

    Lista* lista_e = new Lista();

    for(int i = 0; i < tamanho_teste; i++)
        inserirFim(lista_e, lista_v->dados[i]);
    

    return lista_e;
}

vLista* vetoriarListaEncadeada(Lista* lista)
{
    vLista* lista_v = new vLista;
    lista_v->tamanho = 0;

    No* posAtual = lista->inicio;

    while (posAtual != nullptr && lista_v->tamanho < MAX)
    {
        lista_v->dados[lista_v->tamanho] = posAtual->info;
        lista_v->tamanho++;
        
        posAtual = posAtual->prox;

    }

    return lista_v;
}