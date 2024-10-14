#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Função protótipo para ordenar um vetor com o algoritmo Insertion Sort
void insertionSort(int arr[], int n, long long *comparisons, long long *swaps);
// Função protótipo para ordenar um vetor com o algoritmo Selection Sort
void selectionSort(int arr[], int n, long long *comparisons, long long *swaps);
// Função protótipo para ordenar um vetor com o algoritmo Merge Sort
void mergeSort(int arr[], int p, int r, long long *comparisons, long long *swaps);
// Função protótipo para ordenar um vetor com o algoritmo Heap Sort
void heapSort(int arr[], int n, long long *comparisons, long long *swaps);
// Função protótipo para ordenar um vetor com o algoritmo Quick Sort
void quickSort(int arr[], int p, int r, long long *comparisons, long long *swaps);
// Função protótipo para ordenar um vetor com o algoritmo Quick Sort no pior caso
void quickSortPiorCaso(int arr[], int p, int r, long long *comparisons, long long *swaps);

#endif // SORTING_ALGORITHMS_H