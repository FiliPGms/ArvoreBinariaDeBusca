#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include "Pedido.h"

int main(){
    Lista* listaPedidos = criarLista();

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

    inserirDado(listaPedidos, p1);
    inserirDado(listaPedidos, p2);
    inserirDado(listaPedidos, p3);

    printf("\n--- Lista de pedidos após inserção ---\n");
    imprimirLista(listaPedidos, imprimirPedido);

    printf("\nQuantidade de pedidos na lista: %d\n", quantidadeItens(listaPedidos));

    printf("\nMonstrando Anterior:\n");
    Pedido* ant1 = (Pedido*) mostraAnterior(listaPedidos, 1);
    if (ant1) imprimirPedido(ant1);

    Pedido* ant2 = (Pedido*) mostraAnterior(listaPedidos, 2);
    if (ant2) imprimirPedido(ant2);

    printf("\nTeste de busca:\n");
    for(int i = 0; i < quantidadeItens(listaPedidos); i++){
        Pedido* p = (Pedido*) obter(listaPedidos, i);
        if(p) imprimirPedido(p);
    }

    
    printf("\nRemovendo pedidos...\n");
    while (!listaVazia(listaPedidos)) {
        removerDado(listaPedidos, 0);
    }
    
    if(listaVazia(listaPedidos)){
        printf("lista vazia");
    }

    printf("\nDestruindo lista...\n");
    liberarLista(listaPedidos);
}