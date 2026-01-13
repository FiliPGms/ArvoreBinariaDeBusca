#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"  

typedef struct t_no{
    void* dado;
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

int inserir(Lista* prt_l, void*dado){
    if(prt_l->tamanho = prt_l->capacidade) return 0; //minha lista tá cheia
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->dado = dado;
    if(prt_l->ultimo != NULL){
        prt_l->ultimo->proximo = novo_no;
        novo_no->anterior = prt_l->ultimo;
        novo_no->proximo = NULL;
    }else{
        prt_l->primeiro = novo_no;
        novo_no->anterior = NULL;
        novo_no->proximo = NULL;
    }

    prt_l->ultimo = novo_no;
    prt_l->tamanho++;
    return 1;
}

int remover(Lista* ptr_l, int posicao){
    if(posicao<0 || posicao >= ptr_l->tamanho) return 0;
    No* atual = ptr_l->primeiro;
    for(int i=0;i<posicao;i++){
        atual = atual->proximo;
    }

    if(atual->anterior!=NULL){
        atual->anterior->proximo = atual->proximo;
    }else{
        ptr_l->primeiro = atual->proximo;
    }
    
    if(atual->proximo != NULL){
        atual->proximo->anterior = atual->anterior;
    }else{
        ptr_l->ultimo = atual->anterior;
    }

    free(atual);
    ptr_l->tamanho--;
    return 1;
}

void* obter(Lista* ptr_l, int posicao){
    if(posicao<0 || posicao >= ptr_l->tamanho) return NULL;
    No* atual = ptr_l->primeiro;
    for(int i=0;i<posicao;i++){
        atual = atual->proximo;
    }

    return atual->dado;
}

int cheia(Lista* ptr_l){
    if(ptr_l->tamanho >= ptr_l->capacidade) return 1;
    else return 0;
}

int vazia(Lista* ptr_l){
    if(ptr_l->tamanho == 0) return 1;
    else return 0;
}

int tamanho(Lista* ptr_l){
    return ptr_l->tamanho;
}

int capacidade(Lista* ptr_l){
    return ptr_l->capacidade;
}

void imprimir(Lista* ptr_l, void (*imprimir_dado)(void* dado)){
    No* atual = ptr_l->primeiro;
    while(atual != NULL){
        imprimir_dado(atual->dado);
        atual = atual->proximo;
    }
}