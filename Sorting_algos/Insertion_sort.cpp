//insertion sort technique is used to sort an array by building a sorted portion of the array one element at a time.
// It is a simple and intuitive algorithm that works well for small datasets or nearly sorted data.
// Time Complexity: O(n^2) - in the worst case, the algorithm will perform O(n^2) comparisons and shifts.
// Best Case: O(n) - occurs when the array is already sorted, as the algorithm only needs to make one pass through the array.
// Average Case: O(n^2) - on average, the algorithm will still perform O(n^2) comparisons and shifts.
// Worst Case: O(n^2) - occurs when the array is sorted in reverse order, requiring the maximum number of comparisons and shifts.
// Auxiliary Space Complexity: O(1) - no additional space is used except for a few variables for indexing.
// In-Place: Yes - the algorithm sorts the array without requiring additional storage for another array.
// Space Complexity: O(1) - in-place sorting
// Stable: Yes - insertion sort is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
// Example: If we have two equal elements, they will remain in the same order in the sorted array as they were in the original array.
// Insertion sort is often used in practice for small datasets or as part of more complex algorithms like Timsort (used in Python's sort function).
#include <iostream>
using namespace std;    

void insertionSort(int arr[], int n) {
    for (int i = 0; i <= n-1; i++) {

        int j = i;

        while (j > 0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main() {
    /*int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }*/

    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}