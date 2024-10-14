#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b, long long *swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swaps)++;  // Increment the swap count
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
    int i, j, minIdx, temp;
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
        (*comparisons)++;  // Increment the comparison count
        if (B[i] <= B[j]) {
            arr[k] = B[i];
            i++;
        } else {
            arr[k] = B[j];
            j++;
        }
        k++;
        (*swaps)++;  // Increment the swap count for each assignment to arr[k]
    }

    while (i < n1) {
        arr[k] = B[i];
        i++;
        k++;
        (*swaps)++;  // Increment the swap count for each assignment to arr[k]
    }

    while (j < n1 + n2) {
        arr[k] = B[j];
        j++;
        k++;
        (*swaps)++;  // Increment the swap count for each assignment to arr[k]
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
    int e = 2 * i + 1;  // Left child index
    int d = 2 * i + 2;  // Right child index
    int maior = i;

    if (e < n && arr[e] > arr[i]) {
        (*comparisons)++;  // Counting comparison
        maior = e;
    }

    if (d < n && arr[d] > arr[maior]) {
        (*comparisons)++;  // Counting comparison
        maior = d;
    }

    if (maior != i) {
        (*comparisons)++;  // Counting comparison
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

int particiona(int A[], int p, int r, long long *comparisons, long long *swaps) {
    int pivotIndex = (p + r) / 2;
    int x = A[pivotIndex];  // Pivot element
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        (*comparisons)++;  // Increment number of comparisons
        if (A[j] <= x) {
            i = i + 1;
            troca(&A[i], &A[j], swaps);
        }
    }
    troca(&A[i + 1], &A[r], swaps);
    return i + 1;
}

void quickSort(int A[], int p, int r, long long *comparisons, long long *swaps) {
    if (p < r) {
        int q = particiona(A, p, r, comparisons, swaps);  // Partition the array
        quickSort(A, p, q - 1, comparisons, swaps);      // Sort the left part
        quickSort(A, q + 1, r, comparisons, swaps);      // Sort the right part
    }
}

int particionaPiorCaso(int A[], int p, int r, long long *comparisons, long long *swaps) {
    int x = A[r];  // Pivot element
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        (*comparisons)++;  // Increment number of comparisons
        if (A[j] <= x) {
            i = i + 1;
            troca(&A[i], &A[j], swaps);
        }
    }
    troca(&A[i + 1], &A[r], swaps);
    return i + 1;
}

void quickSortPiorCaso(int A[], int p, int r, long long *comparisons, long long *swaps) {
    if (p < r) {
        int q = particionaPiorCaso(A, p, r, comparisons, swaps);  // Partition the array
        quickSortPiorCaso(A, p, q - 1, comparisons, swaps);      // Sort the left part
        quickSortPiorCaso(A, q + 1, r, comparisons, swaps);      // Sort the right part
    }
}
