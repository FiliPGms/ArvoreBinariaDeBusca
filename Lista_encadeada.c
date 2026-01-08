#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"  

typedef struct t_no{
    int dado;
    No* proximo;
    No* anterior;
}No;

struct t_lista
{
    No* primeiro;
    No* ultimo;
    int tamanho;
    int capacidade;
};

Lista* criarLista(int capacidade){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->capacidade = capacidade;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

void liberarLista(Lista* ptr_l){
    No* atual = ptr_l->primeiro;
    while (atual!=NULL)
    {
        No* temp = atual;
        atual = ptr_l->primeiro->proximo;
        free(temp);
    }
    free(ptr_l);
}