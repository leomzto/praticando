#include "struct.hpp"


NoS* inverterLista(NoS* lista)
{
    if (lista == nullptr || lista->prox == nullptr)
        return lista; // se a lista ta vazia, retorna NULL

    NoS* listaInvertida = inverterLista(lista->prox); // inicio da lista nova é igual ao fim da lista antiga

    lista->prox->prox = lista; // exp: lista: 1 | 2 | 3 | 4 --> lista->prox->prox -> 3->prox = 4

    lista->prox = nullptr; // lista = 3 --> 3->4 = 3 ---> 4->3

    return listaInvertida; // 4 | 3 | 2 | 1
}

void inserirInicio(NoS* &lista, int valor)
{
    NoS* novoNo = new NoS(valor);
    novoNo->prox = lista;
    lista = novoNo;
}

NoS* inverter(NoS* lista)
{
    NoS* lista2 = nullptr;

    NoS* aux = lista;

    while (aux != nullptr)
    {
        inserirInicio(lista2, aux->info); // vai inserindo elemento por elemento no inicio da 2n lista, 
                                         // fazendo com que o primeiro inserido, seja o ultimo da lista

        aux = aux->prox;
    }

    return lista2;
}