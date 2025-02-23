#include <stdio.h>
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
        return;
    }

    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int minL, maxL, minR, maxR;

    findMinMax(arr, low, mid, &minL, &maxL);
    findMinMax(arr, mid + 1, high, &minR, &maxR);
    if (minL < minR) {
          *min = minL;
    } else {
          *min = minR;
    }
    if (maxL > maxR) {
          *max = maxL;
    } else {
          *max = maxR;
    }
}

int main() {
    int arr[100];
    int n, i;
    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMinMax(arr, 0, n - 1, &min, &max);
    printf("The minimum element in the array is: %d\n", min);
    printf("The maximum element in the array is: %d\n", max);
    return 0;
}
