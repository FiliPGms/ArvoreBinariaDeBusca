#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define QTD_REGISTROS 10000
#define ARQUIVO_SAIDA "clientes.txt" // adapte o nome do arquivo conforme necessário


// Bancos de palavras para gerar nomes aleatórios
// adapter para ter as informações necessárias de acordo com o seu TAD 
const char *nomes[] = {"Ana", "Bruno", "Carlos", "Diana", "Eduardo", "Fernanda", "Gustavo", "Helena", "Igor", "Julia", "Lucas", "Mariana", "Nicolas", "Olivia", "Pedro"};
const char *sobrenomes[] = {"Silva", "Santos", "Oliveira", "Souza", "Rodrigues", "Ferreira", "Almeida", "Costa", "Pereira", "Lima", "Gomes", "Martins"};
const char *dominios[] = {"gmail.com", "hotmail.com", "yahoo.com", "outlook.com", "uol.com.br", "tech.com"};

// Função auxiliar para embaralhar o vetor de IDs (Fisher-Yates Shuffle)
// Isso garante que os IDs sejam únicos e aleatórios para balancear sua árvore
void embaralhar_ids(int *vetor, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Função para converter string para minúsculo (para o email)
void str_lower(char *dest, const char *src) {
    int i = 0;
    while(src[i]) {
        dest[i] = tolower(src[i]);
        i++;
    }
    dest[i] = '\0';
}

int main() {
    printf("Iniciando geracao de %d registros...\n", QTD_REGISTROS);
    
    // Inicializa semente do random
    srand(time(NULL));

    // 1. Criar e preencher o array de IDs
    int *ids = (int*) malloc(QTD_REGISTROS * sizeof(int));
    if (ids == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    for (int i = 0; i < QTD_REGISTROS; i++) {
        ids[i] = i + 1; // IDs de 1 a 10000
    }

    // 2. Embaralhar os IDs para evitar Árvore Degenerada
    printf("Embaralhando IDs...\n");
    embaralhar_ids(ids, QTD_REGISTROS);

    // 3. Abrir arquivo para escrita
    FILE *f = fopen(ARQUIVO_SAIDA, "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo!\n");
        free(ids);
        return 1;
    }

    // 4. Gerar nomes e emails e gravar no arquivo
    char nome_completo[100];
    char email[150];
    char nome_lower[50], sobrenome_lower[50];

    int total_nomes = sizeof(nomes) / sizeof(nomes[0]);
    int total_sobrenomes = sizeof(sobrenomes) / sizeof(sobrenomes[0]);
    int total_dominios = sizeof(dominios) / sizeof(dominios[0]);

    for (int i = 0; i < QTD_REGISTROS; i++) {
        // Escolhe partes aleatórias
        const char *n = nomes[rand() % total_nomes];
        const char *s = sobrenomes[rand() % total_sobrenomes];
        const char *d = dominios[rand() % total_dominios];

        // Formata Nome
        sprintf(nome_completo, "%s %s", n, s);

        // Formata Email (ex: bruno.silva@gmail.com)
        str_lower(nome_lower, n);
        str_lower(sobrenome_lower, s);
        sprintf(email, "%s.%s@%s", nome_lower, sobrenome_lower, d);

        // Escreve no arquivo: ID;Nome;Email
        fprintf(f, "%d;%s;%s\n", ids[i], nome_completo, email);
    }

    // Limpeza
    fclose(f);
    free(ids);

    printf("Sucesso! Arquivo '%s' gerado com %d linhas.\n", ARQUIVO_SAIDA, QTD_REGISTROS);
    printf("Exemplo da primeira linha gerada (ID aleatorio): ID %d\n", ids[0]);

    return 0;
}