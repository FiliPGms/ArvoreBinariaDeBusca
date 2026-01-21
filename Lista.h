#ifndef LISTA_H
#define LISTA_H 

typedef struct t_lista Lista;

Lista* criarLista();
void liberarLista(Lista* ptr_l);

int inserirDado(Lista* ptr_l, void* dado);
int removerDado(Lista* ptr_l, int posicao);
void* obterDado(Lista* ptr_l, int posicao);

int listaCheia(Lista* ptr_l);
int listaVazia(Lista* ptr_l);
int quantidadeItens(Lista* ptr_l);

void imprimirLista(Lista* ptr_l, void (*imprimir_dado)(void* dado));
void* mostraAnterior(Lista* ptr_l, int posicao);

#endif