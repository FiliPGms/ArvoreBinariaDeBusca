// teste de arvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    ABB* minha_arvore = criar_arvore(10, NULL);
    inserir(minha_arvore, 15, NULL);
    inserir(minha_arvore, 3, NULL);
    inserir(minha_arvore, 7, NULL);
    inserir(minha_arvore, 12, NULL);
    inserir(minha_arvore, 18, NULL);
    printf("Impressao em ordem: ");
    imprimir_em_ordem(minha_arvore);
    printf("\n");
    printf("Impressao em pos-ordem: ");
    imprimir_pos_ordem(minha_arvore);
    printf("\n");

    printf("Altura da arvore: %d\n", altura(minha_arvore));
    printf("Tamanho da arvore: %d\n", tamanho(minha_arvore));
    printf("Maximo valor na arvore: %d\n", max(minha_arvore));
    printf("Minimo valor na arvore: %d\n", min(minha_arvore));

    remover(minha_arvore, 7);
    remover(minha_arvore, 15);
    printf("Impressao em ordem apos remover 7 e 15: ");
    imprimir_em_ordem(minha_arvore);
    printf("\n");


    liberar_arvore(minha_arvore);
    return 0;
}
