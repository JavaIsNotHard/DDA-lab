#include "random.h"

void generateRandomArray(int *array, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; 
    }
}
