#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortingAlgorithms.h"
#include "arrayUtils.h"

// Tamanhos dos vetores a serem ordenados
int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
int numSizes = 10;
int numTrials = 10;

/* // Função para copiar um vetor para outro
void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
} */

void executeInsertionSort() {
    // Variáveis para medir o tempo de execução
    clock_t start, end;
    double cpu_time_used;
    
    // Arquivos para salvar os resultados
    FILE *fp1 = fopen("insertion_sort_caso_medio.csv", "w");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp2 = fopen("insertion_sort_melhor_caso.csv", "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp3 = fopen("insertion_sort_pior_caso.csv", "w");
    if (fp3 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Cabeçalho dos arquivos CSV
    fprintf(fp1, "Array Size,Trial,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp2, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp3, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    
    // Loop para cada tamanho de vetor
    for (int sizeIdx = 0; sizeIdx < numSizes; sizeIdx++) {
        int size = sizes[sizeIdx];
        int *arr = (int *)malloc(size * sizeof(int));
        // int *arrCopy = (int *)malloc(size * sizeof(int));
        long long comparisons;
        long long swaps;

        generateArrayInOrder(arr, size);
        start = clock();
        insertionSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp2, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);

        generateArrayInReverseOrder(arr, size);
        start = clock();
        insertionSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp3, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);
        
        // Loop para ordenar cada tamanho de vetor 10 vezes
        for (int trial = 1; trial <= numTrials; trial++) {
            // Gera um vetor aleatório
            generateRandomArray(arr, size);
            
            /* // Copy the array to avoid regenerating in each trial
            copyArray(arr, arrCopy, size); */
            
            // Execução do algoritmo de ordenação Insertion Sort
            start = clock();
            insertionSort(arr, size, &comparisons, &swaps);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            
            // Escreve os resultados no arquivo CSV
            fprintf(fp1, "%d,%d,%.6f,%lld,%lld\n", size, trial, cpu_time_used, comparisons, swaps);
        }
        
        free(arr);
        // free(arrCopy);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Empirical analysis completed. Results saved.\n");
}

void executeSelectionSort() {
    // Variáveis para medir o tempo de execução
    clock_t start, end;
    double cpu_time_used;
    
    // Arquivos para salvar os resultados
    FILE *fp1 = fopen("selection_sort_caso_medio.csv", "w");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp2 = fopen("selection_sort_melhor_caso.csv", "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp3 = fopen("selection_sort_pior_caso.csv", "w");
    if (fp3 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Cabeçalho dos arquivos CSV
    fprintf(fp1, "Array Size,Trial,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp2, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp3, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    
    // Loop para cada tamanho de vetor
    for (int sizeIdx = 0; sizeIdx < numSizes; sizeIdx++) {
        int size = sizes[sizeIdx];
        int *arr = (int *)malloc(size * sizeof(int));
        // int *arrCopy = (int *)malloc(size * sizeof(int));
        long long comparisons;
        long long swaps;

        generateArrayInOrder(arr, size);
        start = clock();
        selectionSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp2, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);

        generateArrayInReverseOrder(arr, size);
        start = clock();
        selectionSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp3, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);
        
        // Loop para ordenar cada tamanho de vetor 10 vezes
        for (int trial = 1; trial <= numTrials; trial++) {
            // Gera um vetor aleatório
            generateRandomArray(arr, size);
            
            /* // Copy the array to avoid regenerating in each trial
            copyArray(arr, arrCopy, size); */
            
            // Execução do algoritmo de ordenação Selection Sort
            start = clock();
            selectionSort(arr, size, &comparisons, &swaps);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            
            // Escreve os resultados no arquivo CSV
            fprintf(fp1, "%d,%d,%.6f,%lld,%lld\n", size, trial, cpu_time_used, comparisons, swaps);
        }
        
        free(arr);
        // free(arrCopy);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Empirical analysis completed. Results saved.\n");
}

void executeMergeSort() {
    // Variáveis para medir o tempo de execução
    clock_t start, end;
    double cpu_time_used;
    
    // Arquivos para salvar os resultados
    FILE *fp1 = fopen("merge_sort_caso_medio.csv", "w");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp2 = fopen("merge_sort_melhor_caso.csv", "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp3 = fopen("merge_sort_pior_caso.csv", "w");
    if (fp3 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Cabeçalho dos arquivos CSV
    fprintf(fp1, "Array Size,Trial,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp2, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp3, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    
    
    // Loop para cada tamanho de vetor
    for (int sizeIdx = 0; sizeIdx < numSizes; sizeIdx++) {
        int size = sizes[sizeIdx];
        int *arr = (int *)malloc(size * sizeof(int));
        // int *arrCopy = (int *)malloc(size * sizeof(int));
        long long comparisons = 0;
        long long swaps = 0;

        generateArrayInOrder(arr, size);
        start = clock();
        mergeSort(arr, 0, size - 1, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp2, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);

        comparisons = 0;
        swaps = 0;
        generateArrayInReverseOrder(arr, size);
        start = clock();
        mergeSort(arr, 0, size - 1, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp3, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);
        
        // Loop para ordenar cada tamanho de vetor 10 vezes
        for (int trial = 1; trial <= numTrials; trial++) {
            // Gera um vetor aleatório
            generateRandomArray(arr, size);
            
            /* // Copy the array to avoid regenerating in each trial
            copyArray(arr, arrCopy, size); */
            
            // Execução do algoritmo de ordenação Selection Sort
            comparisons = 0;
            swaps = 0;
            start = clock();
            mergeSort(arr, 0, size - 1, &comparisons, &swaps);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            
            // Escreve os resultados no arquivo CSV
            fprintf(fp1, "%d,%d,%.6f,%lld,%lld\n", size, trial, cpu_time_used, comparisons, swaps);
        }
        
        free(arr);
        // free(arrCopy);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Empirical analysis completed. Results saved.\n");
}

void executeHeapSort() {
    // Variáveis para medir o tempo de execução
    clock_t start, end;
    double cpu_time_used;
    
    // Arquivos para salvar os resultados
    FILE *fp1 = fopen("heap_sort_caso_medio.csv", "w");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp2 = fopen("heap_sort_melhor_caso.csv", "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp3 = fopen("heap_sort_pior_caso.csv", "w");
    if (fp3 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Cabeçalho dos arquivos CSV
    fprintf(fp1, "Array Size,Trial,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp2, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp3, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    
    // Loop para cada tamanho de vetor
    for (int sizeIdx = 0; sizeIdx < numSizes; sizeIdx++) {
        int size = sizes[sizeIdx];
        int *arr = (int *)malloc(size * sizeof(int));
        // int *arrCopy = (int *)malloc(size * sizeof(int));
        long long comparisons = 0;
        long long swaps = 0;

        generateArrayInOrder(arr, size);
        start = clock();
        heapSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp2, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);

        comparisons = 0;
        swaps = 0;
        generateArrayInReverseOrder(arr, size);
        start = clock();
        heapSort(arr, size, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp3, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);
        
        // Loop para ordenar cada tamanho de vetor 10 vezes
        for (int trial = 1; trial <= numTrials; trial++) {
            // Gera um vetor aleatório
            generateRandomArray(arr, size);
            
            /* // Copy the array to avoid regenerating in each trial
            copyArray(arr, arrCopy, size); */
            
            // Execução do algoritmo de ordenação Selection Sort
            comparisons = 0;
            swaps = 0;
            start = clock();
            heapSort(arr, size, &comparisons, &swaps);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            
            // Escreve os resultados no arquivo CSV
            fprintf(fp1, "%d,%d,%.6f,%lld,%lld\n", size, trial, cpu_time_used, comparisons, swaps);
        }
        
        free(arr);
        // free(arrCopy);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Empirical analysis completed. Results saved.\n");
}

void executeQuickSort() {
    // Variáveis para medir o tempo de execução
    clock_t start, end;
    double cpu_time_used;
    
    // Arquivos para salvar os resultados
    FILE *fp1 = fopen("quick_sort_caso_medio.csv", "w");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp2 = fopen("quick_sort_melhor_caso.csv", "w");
    if (fp2 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    FILE *fp3 = fopen("quick_sort_pior_caso.csv", "w");
    if (fp3 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Cabeçalho dos arquivos CSV
    fprintf(fp1, "Array Size,Trial,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp2, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    fprintf(fp3, "Array Size,Execution Time (seconds),Comparisons, Swaps\n");
    
    // Loop para cada tamanho de vetor
    for (int sizeIdx = 0; sizeIdx < numSizes; sizeIdx++) {
        int size = sizes[sizeIdx];
        int *arr = (int *)malloc(size * sizeof(int));
        // int *arrCopy = (int *)malloc(size * sizeof(int));
        long long comparisons = 0;
        long long swaps = 0;

        generateArrayInReverseOrder(arr, size);
        start = clock();
        quickSort(arr, 0, size - 1, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp2, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);

        comparisons = 0;
        swaps = 0;
        generateArrayInReverseOrder(arr, size);
        start = clock();
        quickSortPiorCaso(arr, 0, size - 1, &comparisons, &swaps);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        fprintf(fp3, "%d,%.6f,%lld,%lld\n", size, cpu_time_used, comparisons, swaps);
        
        // Loop para ordenar cada tamanho de vetor 10 vezes
        for (int trial = 1; trial <= numTrials; trial++) {
            // Gera um vetor aleatório
            generateRandomArray(arr, size);
            
            /* // Copy the array to avoid regenerating in each trial
            copyArray(arr, arrCopy, size); */
            
            // Execução do algoritmo de ordenação Selection Sort
            comparisons = 0;
            swaps = 0;
            start = clock();
            quickSort(arr, 0, size - 1, &comparisons, &swaps);
            end = clock();
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
            
            // Escreve os resultados no arquivo CSV
            fprintf(fp1, "%d,%d,%.6f,%lld,%lld\n", size, trial, cpu_time_used, comparisons, swaps);
        }
        
        free(arr);
        // free(arrCopy);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Empirical analysis completed. Results saved.\n");
}
