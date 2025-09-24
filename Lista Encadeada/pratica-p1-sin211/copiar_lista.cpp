#include "struct.hpp"

NoS* copiarLista(NoS* lista)
{
    if (lista == nullptr)
        return nullptr;

    NoS* lista2 = new NoS(lista->info);
    
    NoS* posAtual = lista2;
    NoS* aux = lista->prox;

    while (aux != nullptr)
    {
        NoS* copia = new NoS(aux->info);

        posAtual->prox = copia;
        posAtual = copia;

        aux = aux->prox;
    }

    return lista2;
}
