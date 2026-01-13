#ifndef LISTA_H
#define LISTA_H 

typedef struct t_lista Lista;

Lista* criarLista();
void liberarLista(Lista* ptr_l);

int inserir(Lista* ptr_l, void* dado);
int remover(Lista* ptr_l, int posicao);
void* obter(Lista* ptr_l, int posicao);

int cheia(Lista* ptr_l);
int vazia(Lista* ptr_l);
int quantidade(Lista* ptr_l);

void imprimirLista(Lista* ptr_l, void (*imprimir_dado)(void* dado));
void* mostraAnterior(Lista* ptr_l, int posicao);

#endif