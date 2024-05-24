#include <stdio.h>
#include <time.h>
#include "random.h"

const int MAX_SIZE = 10;

double bubbleSort(clock_t *start, clock_t *end, int *array, int size) {
    *start = clock();
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - 1; j++) {
            if (array[j - 1] > array[j]) {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
    *end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    return cpu_time_used;
}


int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Check if the input size is valid
    if (n <= 0) {
        printf("Error: Array size must be a positive integer.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Generate the random array
    generateRandomArray(array, n);

    // Print the generated array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    start = clock();
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (array[j - 1] > array[j]) {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
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

