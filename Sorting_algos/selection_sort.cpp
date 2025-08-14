//selection sort to sort elements in the asecnding order
// Time Complexity: O(n^2): explaination: for loop i from 0 to n-1, we have a nested loop j from i+1 to n.
// In the worst case, we have to compare each element with every other element, leading to
// sum of n naturalnumbers=(n*(n+1))/2 which simplifies to O(n^2).
// Best Case: O(n^2) - occurs when the array is already sorted, as the algorithm still goes through all comparisons.
// Average Case: O(n^2) - on average, the algorithm will still perform O(n^2) comparisons.
// Worst Case: O(n^2)
// Auxiliary Space Complexity: O(1) - no additional space is used except for a few variables for indexing and swapping.
// In-Place: Yes - the algorithm sorts the array without requiring additional storage for another array
// Space Complexity: O(1) - in-place sorting
// Stable: No
// Unstable: Yes
// Selection sort is not a stable sorting algorithm because it can change the relative order of equal elements
// Example: If we have two equal elements, the one that appears first in the original array
// may not appear first in the sorted array if a swap occurs between them and another element.
// Selection sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional
// space for its operation, making it efficient in terms of memory usage.
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;// finding index of minimum element in unsorted array in every iteration
            }
        }
        // Swap the found minimum element with the first element,
        // next step: swap found min element from the range 1 to n-1 and with the element at index i at index 1.
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    //int arr[] = {13, 46, 24, 20, 9};
    //int n = sizeof(arr) / sizeof(arr[0]);

    int n;
    cin >> n;
    cout << "Enter number of elements: ";  
    int arr[n];
    
    //cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i] ;
        //cout << arr[i] << " "; // Print original array
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
