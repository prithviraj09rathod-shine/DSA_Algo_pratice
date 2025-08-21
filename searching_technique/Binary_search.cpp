/*Time Complexity: O(log n) - Binary search algorithm divides the input array in half at every step, reducing the search space by half, 
and hence has a time complexity of logarithmic order.
Auxiliary Space: O(1) - Binary search algorithm requires only constant space for storing 
the low, high, and mid indices, and does not require any additional data structures,
so its auxiliary space complexity is O(1).
*/
#include<iostream>
#include<vector>
using namespace std;    
// Function to perform binary search
int binarySearch(vector<int> &arr, int target) {
    int left = 0, right = arr.size() - 1;
    // Repeat until the pointers low and 
    // high meet each other
    while (left <= right) {
        int mid = left + (right-left) / 2; // To avoid overflow(//)
        //int mid = (left + right) / 2; // Calculate mid index
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}   

int main() {
    vector<int> arr = {100, 10, 23, 4, 6, 1}; // Sorted array
    int target = 1; // Element to search for and find its index
    // Index of 5 is 4 that we need to find it
    // Ensure the array is sorted before performing binary search
    //sort(arr.begin(), arr.end()); // Sorting the array
   
    // Perform binary search
    cout << "Performing binary search..." << endl;
    cout << "Searching for element: " << target << endl;
    // Call the binary search function
    int index = binarySearch(arr, target);
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}   
