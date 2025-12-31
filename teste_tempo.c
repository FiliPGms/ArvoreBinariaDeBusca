// compara o tempo de busca em arvore balanceada vs vetor desordenado
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h" 
#define NUM_ELEMENTOS 25000
int main() {
// criar uma árvore e um vetor desordenado com NUM_ELEMENTOS elementos. Depois busca um valor que não está presente em ambos, medindo o tempo gasto em cada busca.
    ABB* arvore = NULL;
    int* vetor = (int*)malloc(NUM_ELEMENTOS * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria para o vetor.\n");
        return 1;
    }
    // Inserir elementos na arvore e no vetor
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        arvore = inserir(arvore, i * 2); // inserir apenas numeros pares
        vetor[i] = i * 2;
    }
    int valor_busca = -1; // valor que não está presente
    // Medir tempo de busca na arvore
    clock_t inicio_arvore = clock();
    int encontrado_arvore = buscar(arvore, valor_busca);
    clock_t fim_arvore = clock();
    double tempo_arvore = (double)(fim_arvore - inicio_arvore) / CLOCKS_PER_SEC;
    // Medir tempo de busca no vetor
    clock_t inicio_vetor = clock();
    int encontrado_vetor = 0;
    for (int i = 0; i < NUM_ELEMENTOS; i++) {
        if (vetor[i] == valor_busca) {
            encontrado_vetor = 1;
            break;
        }
    }
    clock_t fim_vetor = clock();
    double tempo_vetor = (double)(fim_vetor - inicio_vetor) / CLOCKS_PER_SEC;
    // Exibir resultados
    printf("Busca na arvore: %s, Tempo: %f segundos\n", encontrado_arvore ? "Encontrado" : "Nao encontrado", tempo_arvore);
    printf("Busca no vetor: %s, Tempo: %f segundos\n", encontrado_vetor ? "Encontrado" : "Nao encontrado", tempo_vetor);
    // Liberar memoria
    liberar_arvore(arvore);
    free(vetor);
    return 0;   


}
