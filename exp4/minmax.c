
#include <stdio.h>

int findMin(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
        
    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            return arr[low];
        } else {
            return arr[high];
        }
    }
        
    int mid = (low + high) / 2;
    int leftMin = findMin(arr, low, mid);
    int rightMin = findMin(arr, mid + 1, high);
    if (leftMin < rightMin) {
        return leftMin;
    } else {
        return rightMin;
    }
}

int findMax(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
        
    if (high - low == 1) {
        if (arr[low] > arr[high]) {
            return arr[low];
        } else {
            return arr[high];
        }
    }
        
    int mid = (low + high) / 2;
    int leftMax = findMax(arr, low, mid);
    int rightMax = findMax(arr, mid + 1, high);
    if (leftMax > rightMax) {
        return leftMax;
    } else {
        return rightMax;
    }
}

int main() {
    int arr[] = {10, 5, 8, 12, 3, 7, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
        
    int min = findMin(arr, 0, n - 1);
    int max = findMax(arr, 0, n - 1);
        
    printf("The minimum element in the array is: %d\n", min);
    printf("The maximum element in the array is: %d\n", max);
    
    return 0;
}
