#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int maxSum = nums[0];      // Global maximum
    int currentSum = nums[0];  // Current subarray sum
    
    for (int i = 1; i < nums.size(); i++) {
        // Either extend current subarray or start new one
        currentSum = max(nums[i], currentSum + nums[i]);
        
        // Update global maximum
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "Maximum subarray sum: " << maxSubarraySum(nums) << endl;
    // Output: 6 (subarray [4, -1, 2, 1])
    
    return 0;
}