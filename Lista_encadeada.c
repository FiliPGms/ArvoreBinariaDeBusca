#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"  

typedef struct t_no{
    void* dado;
    struct t_no* proximo;
    struct t_no* anterior;
}No;

struct t_lista
{
    No* primeiro;
    No* ultimo;
    int qtd;
};

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista != NULL){
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->qtd = 0;
    }
    return lista;
}

void liberarLista(Lista* ptr_l){
    if(ptr_l == NULL) return;
    No* atual = ptr_l->primeiro;
    while (atual!=NULL)
    {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(ptr_l);
}

int inserir(Lista* prt_l, void*dado){
    No* novo_no = (No*)malloc(sizeof(No));
    if(novo_no == NULL) return 0;
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
    prt_l->qtd++;
    return 1;
}

int remover(Lista* ptr_l, int posicao){
    if(ptr_l == NULL) return 0;
    if(posicao<0 || posicao >= ptr_l->qtd) return 0;
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
    ptr_l->qtd--;
    return 1;
}

void* obter(Lista* ptr_l, int posicao){
    if(ptr_l == NULL){
        printf("lista vazia!");
    }
    if(posicao<0 || posicao >= ptr_l->qtd) return NULL;
    No* atual = ptr_l->primeiro;
    for(int i=0;i<posicao;i++){
        atual = atual->proximo;
    }

    return atual->dado;
}

int cheia(Lista* ptr_l){
     return 0;
}

int vazia(Lista* ptr_l){
    if(ptr_l == NULL) return 1;
}

int quantidade(Lista* ptr_l){
    if(ptr_l == NULL) return 0;
    return ptr_l->qtd;
}


void imprimirLista(Lista* ptr_l, void (*imprimir_dado)(void* dado)){
    if(ptr_l == NULL) return; // fila vazia
    No* atual = ptr_l->primeiro;
    while(atual != NULL){
        imprimir_dado(atual->dado);
        atual = atual->proximo;
    }
}

void* mostraAnterior(Lista* ptr_l, int posicao){
    if(posicao<=0 || posicao >= ptr_l->qtd) return NULL;
    No* atual = ptr_l->primeiro;
    for(int i=0;i<posicao;i++){
        atual = atual->proximo;
    }
    return atual->anterior->dado;
}