#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD_REGISTROS 10000
#define ARQUIVO_SAIDA "pedidos.txt"

// Bancos para nomeCliente
const char *nomes[] = {"Ana", "Bruno", "Carlos", "Diana", "Eduardo", "Fernanda", "Gustavo", "Helena", "Igor", "Julia", "Lucas", "Mariana", "Nicolas", "Olivia", "Pedro"};
const char *sobrenomes[] = {"Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Almeida", "Costa", "Pereira", "Lima", "Gomes", "Martins"};

// Banco para nomePedido
const char *itens_cardapio[] = {
    "X-Bacon Artesanal", "Pizza Calabresa", "Suco de Laranja", "Refrigerante Lata",
    "Batata Frita Grande", "Hamburguer Vegano", "Salada Cesar", "Pastel de Queijo",
    "Acai 500ml", "Milkshake Morango", "Sanduiche Natural", "Agua Mineral"
};

// Banco para observacao
const char *lista_observacoes[] = {
    "Sem cebola", "Bem passado", "Sem gelo", "Para viagem",
    "Adicionar maionese", "Cortar ao meio", "Pouco sal", "Mal passado",
    "Sem observacoes", "Molho a parte", "Extra bacon", "Sem observacoes"
};

// Embaralhar o vetor de IDs
void embaralhar_ids(int *vetor, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

int main() {
    printf("Iniciando geracao de %d pedidos...\n", QTD_REGISTROS);

    srand(time(NULL));

    //Criar e embaralhar IDs 
    int *ids = (int*) malloc(QTD_REGISTROS * sizeof(int));
    if (ids == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    for (int i = 0; i < QTD_REGISTROS; i++) {
        ids[i] = i + 1;
    }

    printf("Embaralhando IDs para garantir arvore balanceada...\n");
    embaralhar_ids(ids, QTD_REGISTROS);

    // Abrir arquivo
    FILE *f = fopen(ARQUIVO_SAIDA, "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo!\n");
        free(ids);
        return 1;
    }

    // Loop de Geração
    char nome_cliente[100];

    // Calcula tamanho dos vetores para usar no rand
    int t_nomes = sizeof(nomes) / sizeof(nomes[0]);
    int t_sobrenomes = sizeof(sobrenomes) / sizeof(sobrenomes[0]);
    int t_itens = sizeof(itens_cardapio) / sizeof(itens_cardapio[0]);
    int t_obs = sizeof(lista_observacoes) / sizeof(lista_observacoes[0]);

    for (int i = 0; i < QTD_REGISTROS; i++) {
        // Gerar Nome Cliente
        const char *n = nomes[rand() % t_nomes];
        const char *s = sobrenomes[rand() % t_sobrenomes];
        sprintf(nome_cliente, "%s %s", n, s);

        // Escolher Item e Observação
        const char *item = itens_cardapio[rand() % t_itens];
        const char *obs = lista_observacoes[rand() % t_obs];

        // Gerar Valor (entre R$ 10.00 e R$ 100.00)
        double valor = (rand() % 9000) / 100.0 + 10.0;

        // Escreve no arquivo separado por ponto e vírgula
        fprintf(f, "%d;%s;%s;%s;%.2f\n", ids[i], nome_cliente, item, obs, valor);
    }

    // Limpeza
    fclose(f);
    free(ids);

    printf("Sucesso! Arquivo '%s' gerado.\n", ARQUIVO_SAIDA);
    printf("Formato das linhas: ID;NomeCliente;NomePedido;Observacao;Valor\n");

    return 0;
}
