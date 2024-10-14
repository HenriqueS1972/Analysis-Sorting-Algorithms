#include "executor.h"
//gcc main.c executor.c sortingAlgorithms.c arrayUtils.c -o sort

int main() {
    executeInsertionSort();
    executeSelectionSort();
    executeMergeSort();
    executeHeapSort();
    executeQuickSort();
    
    return 0;
}
