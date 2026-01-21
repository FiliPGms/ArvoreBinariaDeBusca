#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Lista.h"
#include "Pedido.h"
#include "arvore.h"

#define MAX_DADOS 10000
#define INCREMENTO 1000
#define ARQUIVO_DADOS "pedidos.txt"
#define ARQUIVO_RESULTADOS "resultados.txt"

int ler_dados_do_arquivo(Pedido* vetor[]) {
    FILE *f = fopen(ARQUIVO_DADOS, "r");
    if (!f) return 0;

    char linha[512], cliente[100], produto[100], obs[100];
    int id, qtd = 0;
    double valor;

    while (fgets(linha, sizeof(linha), f) && qtd < MAX_DADOS) {
        if (sscanf(linha, "%d;%[^;];%[^;];%[^;];%lf", &id, cliente, produto, obs, &valor) == 5) {
            vetor[qtd] = criarPedido(id, obs, cliente, produto, valor);
            qtd++;
        }
    }
    fclose(f);
    return qtd;
}

void embaralhar(Pedido* vetor[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Pedido* temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    printf("=== COMPARACAO DETALHADA: LISTA vs ARVORE ===\n");

    // Carregar dados
    Pedido* todos_pedidos[MAX_DADOS];
    int total_lidos = ler_dados_do_arquivo(todos_pedidos);

    if (total_lidos < 100) {
        printf("Erro ao ler '%s'.\n", ARQUIVO_DADOS);
        return 1;
    }

    // Arquivo de saída com 5 COLUNAS
    FILE *f_res = fopen(ARQUIVO_RESULTADOS, "w");
    if (!f_res) return 1;

    // Cabeçalho detalhado
    fprintf(f_res, "Quantidade;Lista(Nao Achou);Lista(Achou);Arvore(Nao Achou);Arvore(Achou)\n");

    printf("Qtd\tL(Nao)\t\tL(Sim)\t\tA(Nao)\t\tA(Sim)\n");

    // Loop de Testes
    for (int n = INCREMENTO; n <= total_lidos; n += INCREMENTO) {

        embaralhar(todos_pedidos, total_lidos);

        Lista* lista = criarLista();
        ABB* arvore = NULL;

        // Inserção
        for (int i = 0; i < n; i++) {
            Pedido* p = todos_pedidos[i];
            int id = obterIdPedido(p);
            inserirDado(lista, p);
            arvore = inserir(arvore, id, p);
        }

        // Definir chaves de busca
        int id_existente = obterIdPedido(todos_pedidos[n / 2]); // Pega um do meio
        int id_nao_existente = -1;

        // MEDIÇÃO LISTA
        // Lista: Não encontra
        clock_t t0 = clock();
        int qtd_lista = quantidadeItens(lista);
        for(int i=0; i<qtd_lista; i++){
            Pedido* p = (Pedido*)obterDado(lista, i);
            if(p && obterIdPedido(p) == id_nao_existente) break;
        }
        double tempo_lista_nao = (double)(clock() - t0) / CLOCKS_PER_SEC;

        // Lista: Encontra
        t0 = clock();
        for(int i=0; i<qtd_lista; i++){
            Pedido* p = (Pedido*)obterDado(lista, i);
            if(p && obterIdPedido(p) == id_existente) break;
        }
        double tempo_lista_sim = (double)(clock() - t0) / CLOCKS_PER_SEC;


        // MEDIÇÃO ARVORE
        // Arvore: Não encontra
        t0 = clock();
        buscar(arvore, id_nao_existente);
        double tempo_arvore_nao = (double)(clock() - t0) / CLOCKS_PER_SEC;

        // Arvore: Encontra
        t0 = clock();
        buscar(arvore, id_existente);
        double tempo_arvore_sim = (double)(clock() - t0) / CLOCKS_PER_SEC;


        // Salvar resultados
        fprintf(f_res, "%d;%.6f;%.6f;%.6f;%.6f\n",
                n, tempo_lista_nao, tempo_lista_sim, tempo_arvore_nao, tempo_arvore_sim);

        printf("%d\t%.5f\t%.5f\t%.5f\t%.5f\n",
                n, tempo_lista_nao, tempo_lista_sim, tempo_arvore_nao, tempo_arvore_sim);

        liberarLista(lista);
        liberar_arvore(arvore);
    }

    // Limpeza
    for (int i = 0; i < total_lidos; i++) {
        excluirPedido(todos_pedidos[i]);
    }
    fclose(f_res);
    printf("\nResultados detalhados salvos em '%s'.\n", ARQUIVO_RESULTADOS);

    return 0;
}