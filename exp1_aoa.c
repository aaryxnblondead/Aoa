#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    printf("\nBubble Sort Process:\n");
    for (int i = 0; i < n-1; i++) {
        printf("Pass %d: ", i+1);
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printArray(arr, n);
    }
}

// Modified Bubble Sort (with flag)
void modifiedBubbleSort(int arr[], int n) {
    printf("\nModified Bubble Sort Process:\n");
    int swapped;
    for (int i = 0; i < n-1; i++) {
        printf("Pass %d: ", i+1);
        swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n);
        if (!swapped)
            break;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    printf("\nSelection Sort Process:\n");
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        printf("Pass %d: ", i+1);
        printArray(arr, n);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    printf("\nInsertion Sort Process:\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
        printf("Pass %d: ", i);
        printArray(arr, n);
    }
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n);
    
    bubbleSort(arr1, n);
    modifiedBubbleSort(arr2, n);
    selectionSort(arr3, n);
    insertionSort(arr4, n);
    
    return 0;
}
