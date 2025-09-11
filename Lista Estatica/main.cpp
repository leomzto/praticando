#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

typedef struct sListaEstatica
{
    int dados[MAX];
    int tamanho;

} ListaEstatica;

void inicializarLista(ListaEstatica* lista);

bool listaVazia(ListaEstatica* lista);
bool listaCheia(ListaEstatica* lista);

void inserirInicio(ListaEstatica* lista, int valor);
void inserirFim(ListaEstatica* lista, int valor);
void inserirPosicao(ListaEstatica* lista, int valor, int posicao);

void removerInicio(ListaEstatica* lista);
void removerFim(ListaEstatica* lista);
void removerPosicao(ListaEstatica* lista, int posicao);
void removerValor(ListaEstatica* lista, int valor);

int obterPrimeiroValor(ListaEstatica* lista);
int obterUltimoValor(ListaEstatica* lista);
int obterValorPosicao(ListaEstatica* lista, int posicao);
int obterPosicaoValor(ListaEstatica* lista, int valor);

bool buscarValor(ListaEstatica* lista, int valor);

void imprimirLista(ListaEstatica* lista);


int main(void)
{
    ListaEstatica lista;
    int opc;
    int valor;
    int pos;

    inicializarLista(&lista);

    do {
        cout << "\nOperacoes na lista:" << endl;
        cout << "[1] Inserir no inicio\n" 
             << "[2] Inserir no fim\n" 
             << "[3] Inserir em posicao x (0 <= x < 1000)\n"
             << "[4] Remover do inicio\n" 
             << "[5] Remover do fim\n" 
             << "[6] Remover posicao x (0 <= x < 1000)\n"
             << "[7] Remover valor x\n" 
             << "[8] Obter primeiro valor da lista\n" 
             << "[9] Obter ultimo valor da lista\n"
             << "[10] Obter valor em posicao x (0 <= x < 1000)\n" 
             << "[11] Obter posicao de valor x\n" 
             << "[12] Buscar por valor x\n"
             << "[0] Imprimir a lista\n" 
             << "[-1] Sair\n"
             << "Escolha: ";
        cin >> opc;

        switch (opc)
        {
            case 1:
                cout << "Entre com o valor a ser inserido: ";
                cin >> valor;
                inserirInicio(&lista, valor);
                break;

            case 2:
                cout << "Entre com o valor a ser inserido: ";
                cin >> valor;
                inserirFim(&lista, valor);
                break;

            case 3:
                cout << "Entre com o valor a ser inserido: ";
                cin >> valor;
                cout << "Em qual posicao? ";
                cin >> pos;
                inserirPosicao(&lista, valor, pos);
                break;

            case 4:
                removerInicio(&lista);
                cout << "Valor em Lista[0] removido." << endl;
                break;

            case 5:
                removerFim(&lista);
                cout << "Valor em Lista[lista.tamanho - 1] removido." << endl;
                break;

            case 6:
                cout << "Qual posicao? ";
                cin >> pos;
                removerPosicao(&lista, pos);
                cout << "Valor em Lista[" << pos << "] removido." << endl;
                break;

            case 7:
                cout << "Valor a ser removido da lista: ";
                cin >> valor;
                removerValor(&lista, valor);
                cout << "Valor " << valor << " removido." << endl;
                break;

            case 8:
                valor = obterPrimeiroValor(&lista);
                cout << "Valor de Lista[0]: " << valor << endl;
                break;

            case 9:
                valor = obterUltimoValor(&lista);
                cout << "Valor encontrado em Lista[lista.tamanho - 1]: " << valor << endl;
                break;

            case 10:
                cout << "Em qual posicao? ";
                cin >> pos;
                valor = obterValorPosicao(&lista, pos);
                cout << "Valor encontrado em Lista[" << pos << "]: " << valor << endl;
                break;

            case 11:
                cout << "Qual valor deseja saber a posicao? ";
                cin >> valor;
                pos = obterPosicaoValor(&lista, valor);
                cout << "Posicao do valor " << valor << ": " << pos << endl;
                break;

            case 12:
                cout << "Valor a ser buscado: ";
                cin >> valor;
                cout << (buscarValor(&lista, valor) ? "Esta presente" : "Nao esta presente") << endl;
                break;

            case 0:
                imprimirLista(&lista);
                break;

            case -1:
                cout << "Encerrando." << endl;
                break;

            default:
                cout << "Opcao indisponivel." << endl;
                break;
        }

    } while (opc != -1);

    return 0;
}



void inicializarLista(ListaEstatica* lista)
{
    lista->tamanho = 0;
}

bool listaVazia(ListaEstatica* lista)
{
    return lista->tamanho == 0;
}

bool listaCheia(ListaEstatica* lista)
{
    return lista->tamanho == MAX;
}

void inserirInicio(ListaEstatica* lista, int valor)
{
    if (listaCheia(lista))
    {
        cout << "A lista esta cheia." << endl;
        return;
    }

    for (int i = lista->tamanho - 1; i >= 0; i--)
        lista->dados[i + 1] = lista->dados[i];

    lista->dados[0] = valor;
    lista->tamanho++;
}

void inserirFim(ListaEstatica* lista, int valor)
{
    if (listaCheia(lista))
    {
        cout << "A lista esta cheia." << endl;
        return;
    }

    lista->dados[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserirPosicao(ListaEstatica* lista, int valor, int posicao)
{
    if (listaCheia(lista))
    {
        cout << "A lista esta cheia." << endl;
        return;
    }

    if (posicao >= 0 && posicao <= lista->tamanho)
    {
        for (int i = lista->tamanho - 1; i >= posicao; i--)
            lista->dados[i + 1] = lista->dados[i];

        lista->dados[posicao] = valor;
        lista->tamanho++;
    }
    else
    {
        cout << "Posicao invalida." << endl;
        return;
    }
}

void removerInicio(ListaEstatica* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

    for (int i = 1; i < lista->tamanho; i++)
        lista->dados[i - 1] = lista->dados[i];

    lista->tamanho--;
}

void removerFim(ListaEstatica* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

    lista->tamanho--;
}

void removerPosicao(ListaEstatica* lista, int posicao)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

if (posicao >= 0 && posicao < lista->tamanho)
    {
        int remover = lista->dados[posicao];

        for (int i = posicao + 1; i < lista->tamanho; i++)
            lista->dados[i - 1] = lista->dados[i];

        lista->tamanho--;
    }
    else
    {
        cout << "Posicao invalida." << endl;
        return;
    }
}

void removerValor(ListaEstatica* lista, int valor)
{
    if (listaVazia(lista))
    {
        cout << "A lista está vazia." << endl;
        return;
    }

    int posicao = -1;

    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] == valor)
        {
            posicao = i;
            {
                break;
            }
        }
    }

    if (posicao == -1)
    {
        cout << "Valor não encontrado." << endl;
        return;
    }

    for (int i = posicao + 1; i < lista->tamanho; i++)
        lista->dados[i - 1] = lista->dados[i];

    lista->tamanho--;
}

int obterPrimeiroValor(ListaEstatica* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return -1;
    }
    
    return lista->dados[0];
}

int obterUltimoValor(ListaEstatica* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return -1;
    }

    return lista->dados[lista->tamanho - 1];
}

int obterValorPosicao(ListaEstatica* lista, int posicao)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return -1;
    }

    if (posicao >= 0 && posicao < lista->tamanho)
        return lista->dados[posicao];
    else
    {
        cout << "Posicao invalida." << endl;
        return -1;
    }
}

int obterPosicaoValor(ListaEstatica* lista, int valor)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return -1;
    }

    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->dados[i] == valor)
            return i;
    }

    return -1;
}

bool buscarValor(ListaEstatica* lista, int valor)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return false;
    }

    for (int i = 0; i < lista->tamanho; i ++)
    {
        if (lista->dados[i] == valor)
            return true;
    }

    return false;
}

void imprimirLista(ListaEstatica* lista)
{
    if (listaVazia(lista))
    {
        cout << "A lista esta vazia." << endl;
        return;
    }

    cout << "Lista: ";
    for (int i = 0; i < lista->tamanho; i++)
        cout << lista->dados[i] << " -> ";

    cout << endl;
}

