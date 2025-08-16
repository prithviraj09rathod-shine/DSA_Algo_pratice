//triplets with zero sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

// Function to find triplets with zero sum
vector<vector<int>> findTripletsWithZeroSum(vector<int> &arr) {
    vector<vector<int>> result     ;
    int n = arr.size();
    // Sort the array to use two-pointer technique
    sort(arr.begin(), arr.end());   

    // Iterate through the array
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1]) continue;    
        int left = i + 1; // Left pointer
        int right = n - 1; // Right pointer
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0) {
                result.push_back({arr[i], arr[left], arr[right]});
                // Skip duplicate elements for left pointer
                while (left < right && arr[left] == arr[left + 1]) left++;
                // Skip duplicate elements for right pointer
                while (left < right && arr[right] == arr[right - 1]) right--;
                left++;
                right--;
            } else if (sum < 0) {
                left++; // Move left pointer to increase sum
            } else {
                right--; // Move right pointer to decrease sum
            }
        }
    }
    return result; // Return the list of triplets
}  

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4}; // Example array
    vector<vector<int>> triplets = findTripletsWithZeroSum(arr);
    
    if (triplets.empty()) {
        cout << "No triplets found with zero sum." << endl;
    } else {
        cout << "Triplets with zero sum:" << endl;
        for (const auto &triplet : triplets) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
        }
    }
    return 0;
}
// time complexity: O(n^2) - The outer loop runs n times, and the inner while loop runs at most n times in total, leading to a quadratic time complexity.
// space complexity: O(1) - The space used is for the result vector, which
    