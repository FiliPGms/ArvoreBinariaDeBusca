#ifndef LISTA_H
#define LISTA_H 

typedef struct t_lista Lista;

Lista* criarLista(int capacidade);
void liberarLista(Lista* ptr_l);

int inserir(Lista* ptr_l, void* c);
int remover(Lista* ptr_l, int posicao);
void* obter(Lista* ptr_l, int posicao);

int cheia(Lista* ptr_l);
int vazia(Lista* ptr_l);
int tamanho(Lista* ptr_l);
int capacidade(Lista* ptr_l);

void imprimir(Lista* ptr_l, void (*imprimir_dado)(void* dado));

#endif