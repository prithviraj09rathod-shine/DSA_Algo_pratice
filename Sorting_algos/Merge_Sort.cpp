//Merge sort implementation in C++
// Merge sort is a divide-and-conquer algorithm that divides the array into two halves, sorts each half recursively,
// and then merges the sorted halves back together.
// Time Complexity: O(n log n) - the algorithm divides the array into halves (logarithmic) and merges them (linear), resulting in O(n log n).
// Best Case: O(n log n) - occurs when the array is already sorted, as the algorithm still performs the same number of comparisons and merges.
// Average Case: O(n log n) - on average, the algorithm will still perform O(n log n) comparisons and merges.
// Worst Case: O(n log n) - occurs when the array is sorted in reverse order, requiring the maximum number of comparisons and merges.
// Auxiliary Space Complexity: O(n) - the algorithm requires additional space for the temporary arrays used during merging.
// In-Place: No - merge sort is not an in-place sorting algorithm, as it requires additional storage for the temporary arrays.
// Space Complexity: O(n) - due to the temporary arrays used for merging.
// Stable: Yes - merge sort is a stable sorting algorithm, meaning it preserves the relative order
// of equal elements.
#include <iostream>
using namespace std;    

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid; // Size of right subarray

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free temporary arrays
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left == right) return; // Base case: if the array has one element, it's already sorted
    // Recursive case: if the array has more than one element
    // Divide the array into two halves and sort each half
    // The base case is when the left index is greater than or equal to the right index
    if (left >= right) return; 
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}   

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// Merge sort is often used in practice for large datasets or when stability is required.
// It is also the basis for more complex algorithms like Timsort (used in Python's sort function).
// Merge sort is not an in-place sorting algorithm, as it requires additional storage for the temporary arrays used during merging.
// However, it is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
// Example: If we have two equal elements, they will remain in the same order in the sorted array as they were in the original array.
// Merge sort is particularly useful for sorting linked lists, as it can be implemented without additional space
// by using pointers instead of arrays.
