// teste de arvore
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "Pedido.h"

int main() {

    Pedido* p1 = criarPedido(
        1,
        "Sem cebola",
        "João Silva",
        "Hambúrguer",
        25.00
    );

    Pedido* p2 = criarPedido(
        2,
        "Pouco sal",
        "Maria Santos",
        "Lasanha",
        32.50
    );

    Pedido* p3 = criarPedido(
        3,
        "Bem passado",
        "Carlos Lima",
        "Bife Acebolado",
        28.00
    );

    ABB* minha_arvore = criar_arvore(10, NULL);
    inserir(minha_arvore, obterIdPedido(p1), p1);
    inserir(minha_arvore, obterIdPedido(p2), p2);
    inserir(minha_arvore, obterIdPedido(p3), p3);

    printf("Impressão em pré-ordem: ");
    imprimir_pre_ordem(minha_arvore);
    printf("\n");
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
