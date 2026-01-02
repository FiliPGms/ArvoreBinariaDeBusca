// implementacao de funcoes para manipulacao de arvores binarias
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


// Definicao da estrutura da arvore binaria de busca
struct t_arvore {
    int chave; // chave de busca, por exemplo um id de Cliente
    void * dados; // ponteiro para dados adicionais na lista (opcional)
    ABB* esquerda; // ponteiro para subarvore esquerda
    ABB* direita; // ponteiro para subarvore direita
};

ABB* criar_arvore(int chave, void * dados) {
    ABB* nova_arvore = (ABB*)malloc(sizeof(ABB));
    if (nova_arvore != NULL) {
        nova_arvore->chave = chave;
        nova_arvore->dados = dados;
        nova_arvore->esquerda = NULL;
        nova_arvore->direita = NULL;
    }
    return nova_arvore;
}

void liberar_arvore(ABB* arvore) {
    if (arvore != NULL) {
        liberar_arvore(arvore->esquerda);
        liberar_arvore(arvore->direita);
        free(arvore);
    }
}

ABB* inserir(ABB* arvore, int chave, void * dados) {
    if (arvore == NULL) {
        return criar_arvore(chave, dados);
    }
    if (chave < arvore->chave) {
        arvore->esquerda = inserir(arvore->esquerda, chave, dados);
    } else if (chave > arvore->chave) {
        arvore->direita = inserir(arvore->direita, chave, dados);
    }
    return arvore;
}

ABB* remover(ABB* arvore, int chave) {
    if (arvore == NULL) {
        return NULL;
    }
    if (chave < arvore->chave) {
        arvore->esquerda = remover(arvore->esquerda, chave);
    } else if (chave > arvore->chave) {
        arvore->direita = remover(arvore->direita, chave);
    } else {
        // No com um filho ou nenhum filho
        if (arvore->esquerda == NULL) {
            ABB* temp = arvore->direita;
            free(arvore);
            return temp;
        } else if (arvore->direita == NULL) {
            ABB* temp = arvore->esquerda;
            free(arvore);
            return temp;
        }
        // No com dois filhos: obter o menor chave na subarvore direita usando min(ABB* arvore)

        ABB* temp = arvore->direita;
        int minimo = min(temp); // encontrar o sucessor inorder

        arvore->chave = minimo; // copiar a chave do sucessor
        arvore->direita = remover(arvore->direita, minimo); // remover o sucessor
    }
    return arvore;
}


int buscar(ABB* arvore, int chave) {
    if (arvore == NULL) {
        return 0; // chave nao encontrada
    }
    if (chave < arvore->chave) {
        return buscar(arvore->esquerda, chave);
    } else if (chave > arvore->chave) {
        return buscar(arvore->direita, chave);
    } else {
        return 1; // chave encontrada
    }
}

void imprimir_em_ordem(ABB* arvore) {
    if (arvore != NULL) {
        imprimir_em_ordem(arvore->esquerda);
        printf("%d ", arvore->chave);
        imprimir_em_ordem(arvore->direita);
    }
}

void imprimir_pre_ordem(ABB* arvore) {
    if (arvore != NULL) {
        printf("%d ", arvore->chave);
        imprimir_pre_ordem(arvore->esquerda);
        imprimir_pre_ordem(arvore->direita);
    }
}

void imprimir_pos_ordem(ABB* arvore) {
    if (arvore != NULL) {
        imprimir_pos_ordem(arvore->esquerda);
        imprimir_pos_ordem(arvore->direita);
        printf("%d ", arvore->chave);
    }
}   
int altura(ABB* arvore) {
    if (arvore == NULL) {
        return -1; // altura de arvore vazia
    }
    int altura_esquerda = altura(arvore->esquerda);
    int altura_direita = altura(arvore->direita);
    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}
int tamanho(ABB* arvore) {
    if (arvore == NULL) {
        return 0;
    }
    return 1 + tamanho(arvore->esquerda) + tamanho(arvore->direita);
}
int esta_vazia(ABB* arvore) {
    return arvore == NULL;
}

int max(ABB* arvore) {
    if (arvore == NULL) {
        return -1; // arvore vazia
    }
    ABB* atual = arvore;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->chave;
}

int min(ABB* arvore) {
    if (arvore == NULL) {
        return -1; // arvore vazia
    }
    ABB* atual = arvore;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->chave;
}

