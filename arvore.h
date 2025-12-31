// TAD Arvore Binaria de Busca
#ifndef ARVORE_H
#define ARVORE_H    

typedef struct t_arvore ABB; // tipo opaco

// Cria uma arvore vazia
ABB* criar_arvore(int chave, void * dados);
// Libera a memoria ocupada pela arvore
void liberar_arvore(ABB* arvore);
// Insere um elemento na arvore
ABB* inserir(ABB* arvore, int chave, void * dados);
// Remove um elemento da arvore
ABB* remover(ABB* arvore, int chave);
// Busca um elemento na arvore
int buscar(ABB* arvore, int chave);
// Imprime a arvore em ordem 
void imprimir_em_ordem(ABB* arvore);
// Imprime a arvore em pre-ordem
void imprimir_pre_ordem(ABB* arvore);
// Imprime a arvore em pos-ordem
void imprimir_pos_ordem(ABB* arvore);
// Retorna a altura da arvore
int altura(ABB* arvore);
// Retorna o numero de elementos na arvore
int tamanho(ABB* arvore);
// Verifica se a arvore esta vazia
int esta_vazia(ABB* arvore);       
// encontra o menor chave na arvore
int max(ABB* arvore);
// encontra o maior chave na arvore
int min(ABB* arvore);
#endif // ARVORE_H
