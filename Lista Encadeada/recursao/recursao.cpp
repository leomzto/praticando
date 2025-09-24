#include <bits/stdc++.h>

typedef struct No {
    int valor;
    struct No* prox;

    No(int valor) : valor(valor), prox(nullptr) {};
} No;

int contarElementos(No* lista)
{
    if (lista == nullptr || lista->prox == nullptr)
        return 0; // lista vazia retorna 0 elementos presentes

    return 1 + contarElementos(lista->prox); // se a lista nao ta vazia, retorna 1, mais o retorno da proxima chamada, ou seja, se tiver 2 elementos, retorna 1 + 1
}

int somarValores(No* lista)
{
    if (lista == nullptr)
        return 0; // lista vazia retorna soma = 0
    
    return lista->valor + somarValores(lista->prox); // se tem pelo menos 1 elelmento na lista, soma o elemento + o proximo, ate a lista acabar
}

bool buscarElemento(No* lista, int elemento)
{
    if (lista == nullptr)
        return false; // lista vazia, sem elemento presente
    
    if (lista->valor == elemento)
        return true; // se o elemento da lista for igual ao elemento buscado, retorna true (encontrou)

    return buscarElemento(lista->prox, elemento); // se ainda nao achou o elemento, faz a bbusca novamente, agora, olhando o proximo no da lista
}

No* removerElemento(No* lista, int elemento)
{
    if (lista == nullptr)
        return nullptr; // // ou return lista ----> lista vazia, sem elementos para remover, retorna a lista vazia/ NULL

    if (lista->valor == elemento)
    {
        No* proximo = lista->prox; // cria um no auxiliar para referenciar o proximo no da lista antes de deletar o atual
        delete lista;              // limpa a memoria do no atual ***nao pode mais acessar lista
        return removerElemento(proximo, elemento); // funçao chama a si propria, agora com o proximo elemento da lista e retorna o resultado
    }
    // se nao
    lista->prox = removerElemento(lista->prox, elemento); // proximo elemento agora é o que é comparado
    return lista;
}

No* inverterLista(No* lista)
{
    if (lista == nullptr || lista->prox == nullptr)
        return lista; // lista vazia, nao tem o que inverter, retorna ela mesmo / NULL

    No* novoInicio = inverterLista(lista->prox); // lista->prox chegou em null ? inicio agora é o fim da lista : continua

    lista->prox->prox = lista; // faz o proximo no apontar pro no atual ----> lista: 1 | 2 | 3 --> lista->prox = 3 ou seja, 3->prox = 2

    lista->prox = nullptr; // quebra o ponteiro original (2->prox = 3) **deixa o no atual da lista de apontar pra frente

    return novoInicio; // retorna a lista, agora iniciando do novo inicio dela (antigo fim)
}

int maiorElemento(No* lista)
{
    if (lista == nullptr)
        return -9999999; // se a lista vazia retorn -99999 (um retorno de erro, tem q ser algo menor que qualquer valor possivel na lista)

    int max = maiorElemento(lista->prox); // chama a lista recursivamente, agora no proximo elemento e guarda em max
    return (lista->valor > max) ? lista->valor : max; // se o valor atual for maior que o guardado em max, retorna lista>valor, se nao retorna o max
}