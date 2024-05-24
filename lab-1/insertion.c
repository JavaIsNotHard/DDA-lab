#include "random.h"
#include <stdio.h>
#include <time.h>

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
    for (int i = 1; i < n; i++) {
        temp = array[i];
        int j = i - 1;
        while (temp <= array[j] && j >= 0) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = temp;
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

