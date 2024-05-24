#include <stdio.h>
#include "random.h"
#include <time.h>

void selectionSort(int *array, int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; i++) {
        // Assume the current element is the minimum
        minIndex = i;

        // Check the rest of the array for a smaller element
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main() {
    int n, temp;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Array size must be a positive integer.\n");
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    generateRandomArray(array, n);

    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    start = clock();
    selectionSort(array, n);
    end = clock();

    cpu_time_used = ((double)(end-start)*1000)/ CLOCKS_PER_SEC;

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\nTime=%lf milli seconds",cpu_time_used);

    free(array);

    return 0;
}

