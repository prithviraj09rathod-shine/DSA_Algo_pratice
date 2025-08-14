//Bubble sort implementation in C++
// Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements,
// and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
// Time Complexity: O(n^2) - in the worst case, the algorithm will perform O(n^2) comparisons and swaps.
// Best Case: O(n) - occurs when the array is already sorted, as the algorithm will only make one pass through the array.
//// Average Case: O(n^2) - on average, the algorithm will still perform O(n^2) comparisons and swaps.
// Worst Case: O(n^2) - occurs when the array is sorted in reverse order, requiring the maximum number of comparisons and swaps.
// Auxiliary Space Complexity: O(1) - no additional space is used except for a few variables for indexing and swapping.
// In-Place: Yes - the algorithm sorts the array without requiring additional storage for another array.
// Space Complexity: O(1) - in-place sorting
// Stable: Yes - bubble sort is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
// Example: If we have two equal elements, they will remain in the same order in the sorted array as they were in the original array
#include <iostream>
using namespace std;        

void bubbleSort(int arr[], int n) {
    for (int i = n-1; i >= 0; i--) {
        bool swapped = false; // Flag to check if any swapping occurred
        for (int j = 0; j <= i - 1 ; j++) {
            if (arr[j] > arr[j + 1]) {//if want in deescending order, change to <   
                swap(arr[j], arr[j + 1]);
                swapped = true; // Set flag to true if a swap occurred
            }
        }
        if (!swapped) { // If no swaps occurred, the array is sorted
            break;
        }
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

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}