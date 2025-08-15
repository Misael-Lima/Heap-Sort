#include <stdio.h>


// Função para trocar dois elementos de lugar
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ajustar o heap (heapify)
// n = tamanho do heap, i = índice atual
void heapify(int vetor[], int n, int i) {
    int maior = i;          // Assume que o maior elemento é a raiz
    int esquerda = 2 * i + 1; // Filho esquerdo
    int direita = 2 * i + 2;  // Filho direito

    // Se o filho esquerdo é maior que o pai
    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    // Se o filho direito é maior que o maior até agora
    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    // Se o maior não for o pai
    if (maior != i) {
        trocar(&vetor[i], &vetor[maior]);
        // Ajusta recursivamente o sub-heap afetado
        heapify(vetor, n, maior);
    }
}

// Função principal do Heap Sort
void heapSort(int vetor[], int n) {
    // Construir o heap (reorganizar o vetor)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    // Extrair elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz (maior elemento) para o final
        trocar(&vetor[0], &vetor[i]);
        // Chama heapify na parte reduzida do heap
        heapify(vetor, i, 0);
    }
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    heapSort(vetor, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
