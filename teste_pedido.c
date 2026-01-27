#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pedido.h"

int main() {

    printf("Tentando criar um pedido...\n");
    Pedido* meuPedido = criarPedido(
        101,
        "Sem cebola",
        "Carlos Silva",
        "X-Tudo Artesanal",
        35.50
    );

    if (meuPedido != NULL) {
        printf("Pedido criado na memoria\n");
    } else {
        printf("Falha ao criar pedido\n");
        return 1;
    }
    printf("\n");

    printf("Verificando os dados gravados:\n");
    printf("ID: %d\n", obterIdPedido(meuPedido));
    printf("Cliente: %s\n", obterNomeCliente(meuPedido));
    printf("Valor: %.2f\n", obterValorPedido(meuPedido));
    printf("\n");

    printf("Alterando dados do pedido...\n");

    alterarValor(meuPedido, 40.00);

    alterarObservacao(meuPedido, "Sem cebola e com maionese extra");

    alterarNomeCliente(meuPedido, "Carlos Silva Junior");

    printf("Novo Valor: %.2f\n", obterValorPedido(meuPedido));
    printf("Nova Obs: %s\n", obterObservacao(meuPedido));
    printf("Novo Cliente: %s\n", obterNomeCliente(meuPedido));
    printf("\n");

    printf("Testando a funcao imprimirPedido:\n");
    imprimirPedido(meuPedido);
    printf("\n");

    printf("Excluindo pedido e liberando memoria...\n");
    excluirPedido(meuPedido);
    imprimirPedido(meuPedido);
    printf("\n");

    printf("Atribuindo NULL e testando...\n");
    meuPedido = NULL;
    imprimirPedido(meuPedido);
    printf("\n");

    printf("   Tentando excluir pedido ja nulo...\n");
    excluirPedido(meuPedido);
    imprimirPedido(meuPedido);
    printf("\n");

    return 0;
}
