    #include <stdio.h>
    #define MAX_SIZE 1000
    void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    }
    int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
    i++;
    swap(&arr[i], &arr[j]);
    }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
    }
    int kthSmallest(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
    int pos = partition(arr, left, right);
    if (pos - left == k - 1)
    return arr[pos];
    if (pos - left > k - 1)
    return kthSmallest(arr, left, pos - 1, k);
    return kthSmallest(arr, pos + 1, right, k - pos + left - 1);
    }
    return -1;
    }
    int main() {
    int n, k;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
    printf("Invalid array size\n");
    return 1;
    }
    int arr[MAX_SIZE];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    if (k > n) {
    printf("k cannot be greater than size of array\n");
    return 1;
    }
    int result = kthSmallest(arr, 0, n - 1, k);
    if (result != -1)
    printf("The %dth smallest element is: %d\n", k, result);
    else
    printf("Invalid input\n");
    return 0;
}