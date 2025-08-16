// Two pointer technique is used to find pairs in a sorted array
#include <iostream>
#include <vector>
using namespace std;        

// Function to find pairs with a given sum using two pointers
void findPairsWithSum(vector<int> &arr, int targetSum) {
    int left = 0, right = arr.size() - 1;
    bool found = false; 
    // Ensure the array is sorted before using two pointers
    //sort(arr.begin(), arr.end()); // Uncomment if the array is not sorted         
    
    while (left < right) {  
        int currentSum = arr[left] + arr[right];
        if (currentSum == targetSum) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            found = true;
            left++;
            right--;
        } else if (currentSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }
    if (!found) {
        cout << "No pairs found with sum " << targetSum << endl;
    }
}           

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; // Sorted array
    int targetSum = 8; // Target sum to find pairs for
    cout << "Finding pairs with sum " << targetSum << "..." << endl;
    findPairsWithSum(arr, targetSum);
    return 0;
}

