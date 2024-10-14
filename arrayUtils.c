#include <stdlib.h>

// Função para gerar um vetor com valores inteiros aleatórios
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;  // Números aleatórios entre 0 e 99999
    }
}

void generateArrayInOrder(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void generateArrayInReverseOrder(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}
