#include <stdio.h>

// Function to perform Bubble Sort and count swaps
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Increment swap count for the swapped values
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    printf("Bubble Sort - Total # of swaps: %d\n", totalSwaps);
}

// Function to perform Selection Sort and count swaps
void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap elements
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Increment swap count for the swapped values
        swaps[arr[i]]++;
        swaps[arr[minIndex]]++;
        totalSwaps++;
    }
    printf("Selection Sort - Total # of swaps: %d\n", totalSwaps);
}

// Function to print swaps for each value
void printSwaps(int swaps[], int size) {
    for (int i = 0; i < size; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d\n", i, swaps[i]);
        }
    }
    printf("\n");
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    // Initialize swap counters
    int swaps1[100] = {0};  // Assuming values are in the range 0-99
    int swaps2[100] = {0};

    // Bubble Sort and print swaps for array1
    printf("array1:\n");
    bubbleSort(array1, size1, swaps1);
    printSwaps(swaps1, 100);

    // Reset swap counters
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
    }

    // Selection Sort and print swaps for array1
    printf("array1:\n");
    selectionSort(array1, size1, swaps1);
    printSwaps(swaps1, 100);

    // Reset swap counters
    for (int i = 0; i < 100; i++) {
        swaps2[i] = 0;
    }

    // Bubble Sort and print swaps for array2
    printf("array2:\n");
    bubbleSort(array2, size2, swaps2);
    printSwaps(swaps2, 100);

    // Reset swap counters
    for (int i = 0; i < 100; i++) {
        swaps2[i] = 0;
    }

    // Selection Sort and print swaps for array2
    printf("array2:\n");
    selectionSort(array2, size2, swaps2);
    printSwaps(swaps2, 100);

    return 0;
}
