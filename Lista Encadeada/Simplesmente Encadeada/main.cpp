#include "lse.h"

int main(void)
{
    srand(time(0));

    // criar e inserir elementos
    Lista* lista = new Lista();
    inserirFim(lista, 10);
    inserirFim(lista, 20);
    inserirFim(lista, 30);
    inserirInicio(lista, 5);

    cout << "Lista inicial:" << endl;
    imprimirLista(lista);

    // remover elementos
    removerInicio(lista);
    removerFim(lista);

    cout << "\nLista apos remover inicio e fim:" << endl;
    imprimirLista(lista);

    // copiar lista
    Lista* copia = copiarLista(lista);
    cout << "\nLista copiada:" << endl;
    imprimirLista(copia);

    // inverter lista
    Lista* invertida = inverterLista(lista);
    cout << "\nLista invertida:" << endl;
    imprimirLista(invertida);

    // concatenar listas
    Lista* lista2 = new Lista();
    inserirFim(lista2, 100);
    inserirFim(lista2, 200);

    Lista* concatenada = concatenarListas(lista, lista2);
    cout << "\nListas concatenadas:" << endl;
    imprimirLista(concatenada);

    // remover repetidos e ordenar
    inserirFim(concatenada, 20);
    inserirFim(concatenada, 100);
    cout << "\nConcatenada com repetidos:" << endl;
    imprimirLista(concatenada);

    removerRepetidos(concatenada);
    cout << "\nConcatenada sem repetidos:" << endl;
    imprimirLista(concatenada);

    ordenarLista(concatenada);
    cout << "\nConcatenada ordenada:" << endl;
    imprimirLista(concatenada);

    // dividir lista
    Lista* dividida = dividirLista(concatenada, 3);
    cout << "\nPrimeira parte da lista dividida:" << endl;
    imprimirLista(concatenada);

    cout << "Segunda parte da lista dividida:" << endl;
    imprimirLista(dividida);

    // listas iguais
    bool iguais = listasIguais(copia, lista);
    cout << "\nCopia e lista sao iguais? " << (iguais ? "Sim" : "Nao") << endl;

    // vetorizar e encadear vetor
    vLista* v = vetoriarListaEncadeada(lista);
    cout << "\nVetor da lista:" << endl;
    for (int i = 0; i < v->tamanho; i++)
        cout << v->dados[i] << " ";
    cout << endl;

    Lista* novaEncadeada = encadearVetor(v);
    cout << "\nLista encadeada a partir do vetor:" << endl;
    imprimirLista(novaEncadeada);

    // liberar memoria
    liberarLista(lista);
    liberarLista(copia);
    liberarLista(invertida);
    liberarLista(lista2);
    liberarLista(concatenada);
    liberarLista(dividida);
    liberarLista(novaEncadeada);
    delete v;

    return 0;
}
