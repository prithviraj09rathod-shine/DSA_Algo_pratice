//largest element in an array using linear search
#include <iostream>
using namespace std;        
int largestElement(int arr[], int n) {
    int maxElement = arr[0]; // Assume first element is the largest
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update maxElement if current element is larger
        }
    }
    return maxElement;
}   

int main() {
    int arr[] = {3, 5, 2, 8, 6}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array
    int largest = largestElement(arr, n); // Call function to find largest element
    cout << "Largest element in the array: " << largest << endl; // Output the result
    return 0;
}
// This code defines a function to find the largest element in an array using linear search.
// It iterates through the array, comparing each element to find the maximum value.
// The main function demonstrates the usage of this function with an example array.
// The time complexity is O(n) where n is the number of elements in the array,
// as it requires a single pass through the array to find the largest element.
// The space complexity is O(1) since it uses a constant amount of space for the maxElement variable.