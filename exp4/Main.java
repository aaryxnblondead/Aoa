public class Main {
    public static void findMinMax(int[] arr, int low, int high, int[] result) {
        if (low == high) {
            result[0] = arr[low];  // min
            result[1] = arr[low];  // max
            return;
        }
        
        if (high - low == 1) {
            result[0] = Math.min(arr[low], arr[high]);  // min
            result[1] = Math.max(arr[low], arr[high]);  // max
            return;
        }
        
        int mid = (low + high) / 2;
        int[] leftResult = new int[2];
        int[] rightResult = new int[2];
        
        findMinMax(arr, low, mid, leftResult);
        findMinMax(arr, mid + 1, high, rightResult);
        
        result[0] = Math.min(leftResult[0], rightResult[0]);  // min
        result[1] = Math.max(leftResult[1], rightResult[1]);  // max
    }
    
    public static void main(String[] args) {
        int[] arr = {10, 5, 8, 12, 3, 7, 9, 1};
        int n = arr.length;
        
        int[] result = new int[2];  // result[0] for min, result[1] for max
        findMinMax(arr, 0, n - 1, result);
        
        System.out.println("The minimum element in the array is: " + result[0]);
        System.out.println("The maximum element in the array is: " + result[1]);
    }
}