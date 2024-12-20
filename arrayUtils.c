#include <stdlib.h>

// Função para gerar um vetor com valores inteiros aleatórios
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;  // Números aleatórios entre 0 e 99999
    }
}

// Função para gerar um vetor ordenado de forma crescente
void generateArrayInOrder(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

// Função para gerar um vetor ordenado de forma decrescente
void generateArrayInReverseOrder(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}
