#include <stdio.h>
#include <stdlib.h>
#include "sortingAlgorithms.h"

int main() {
    int array[10] = {3, 5, 1, 7, 6, 2, 8, 4, 9, 0};
    long long comps;

    //mergeSort(array, 0, 9, &comps);
    //heapSort(array, 10, &comps);
    quickSort(array, 0, 9, &comps);

    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
}