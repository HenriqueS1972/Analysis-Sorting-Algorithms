#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b, long long *swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swaps)++;
}

void insertionSort(int arr[], int n, long long *comparisons, long long *swaps) {
    int i, key, j;
    *comparisons = 0;
    *swaps = 0;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;  // Contando a comparação arr[j] > key
            arr[j + 1] = arr[j];
            j = j - 1;
            (*swaps)++;  // Contando a troca arr[j + 1] = arr[j]
        }
        if (j >= 0) {
            (*comparisons)++;  // Contando a comparação final quando arr[j] <= key
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, long long *comparisons, long long *swaps) {
    int i, j, minIdx;
    *comparisons = 0;
    *swaps = 0;
    
    for (i = 0; i < n-1; i++) {
        minIdx = i;
        for (j = i+1; j < n; j++) {
            (*comparisons)++;  // Contando a comparação arr[j] < arr[minIdx]
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            troca(&arr[minIdx], &arr[i], swaps);
        }
    }
}

void intercala(int arr[], int p, int q, int r, long long *comparisons, long long *swaps) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int *B = (int *)malloc((r - p + 1) * sizeof(int));
    if (B == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++) {
        B[i] = arr[p + i];
    }
    for (j = 0; j < n2; j++) {
        B[n1 + j] = arr[q + 1 + j];
    }

    i = 0;
    j = n1;
    k = p;
    while (i < n1 && j < n1 + n2) {
        (*comparisons)++;
        if (B[i] <= B[j]) {
            arr[k] = B[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
        (*swaps)++;
    }

    while (i < n1) {
        arr[k] = B[i];
        i++;
        k++;
        (*swaps)++;
    }

    while (j < n1 + n2) {
        arr[k] = B[j];
        j++;
        k++;
        (*swaps)++;
    }

    free(B);
}

void mergeSort(int arr[], int p, int r, long long *comparisons, long long *swaps) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q, comparisons, swaps);
        mergeSort(arr, q + 1, r, comparisons, swaps);
        intercala(arr, p, q, r, comparisons, swaps);
    }
}

void maxHeapify(int arr[], int n, int i, long long *comparisons, long long *swaps) {
    int e = 2 * i + 1;
    int d = 2 * i + 2;
    int maior = i;

    if (e < n && arr[e] > arr[i]) {
        (*comparisons)++;
        maior = e;
    }

    if (d < n && arr[d] > arr[maior]) {
        (*comparisons)++;
        maior = d;
    }

    if (maior != i) {
        (*comparisons)++;
        troca(&arr[i], &arr[maior], swaps);
        maxHeapify(arr, n, maior, comparisons, swaps);
    }
}

void buildMaxHeap(int arr[], int n, long long *comparisons, long long *swaps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i, comparisons, swaps);
    }
}

void heapSort(int arr[], int n, long long *comparisons, long long *swaps) {
    buildMaxHeap(arr, n, comparisons, swaps);
    for (int i = n - 1; i > 0; i--) {
        troca(&arr[0], &arr[i], swaps);
        maxHeapify(arr, i, 0, comparisons, swaps);
    }
}

int particiona(int arr[], int p, int r, long long *comparisons, long long *swaps) {
    int pivotIndex = (p + r) / 2; // Índice do pivô
    int x = arr[pivotIndex];  // Elemento pivô
    troca(&arr[pivotIndex], &arr[r], swaps);
    int i = p - 1;

    for (int j = p; j < r; j++) {
        (*comparisons)++;
        if (arr[j] <= x) {
            i = i + 1;
            troca(&arr[i], &arr[j], swaps);
        }
    }
    troca(&arr[i + 1], &arr[r], swaps);
    return i + 1;
}

void quickSort(int arr[], int p, int r, long long *comparisons, long long *swaps) {
    if (p < r) {
        int q = particiona(arr, p, r, comparisons, swaps);
        quickSort(arr, p, q - 1, comparisons, swaps);
        quickSort(arr, q + 1, r, comparisons, swaps);
    }
}

int particionaPiorCaso(int arr[], int p, int r, long long *comparisons, long long *swaps) {
    int pivotIndex = r; // Índice do pivô
    int x = arr[pivotIndex];  // Elemento pivô
    troca(&arr[pivotIndex], &arr[r], swaps);
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        (*comparisons)++;
        if (arr[j] <= x) {
            i = i + 1;
            troca(&arr[i], &arr[j], swaps);
        }
    }
    troca(&arr[i + 1], &arr[r], swaps);
    return i + 1;
}

void quickSortPiorCaso(int arr[], int p, int r, long long *comparisons, long long *swaps) {
    if (p < r) {
        int q = particionaPiorCaso(arr, p, r, comparisons, swaps);
        quickSortPiorCaso(arr, p, q - 1, comparisons, swaps);
        quickSortPiorCaso(arr, q + 1, r, comparisons, swaps);
    }
}
