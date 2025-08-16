//second largest.cpp
#include <iostream>
#include <vector>       
#include <climits>
using namespace std;    
// Function to find the second largest element in an array
int findSecondLargest(const vector<int> &arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int num : arr) {
        if (num > first) {
            second = first; // Update second largest
            first = num; // Update largest
        } else if (num > second && num < first) {
            second = num; // Update second largest if num is not equal to first
        }
    }
    return second; // Return the second largest element
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1}; // Example array
    int secondLargest = findSecondLargest(arr);
    if (secondLargest != INT_MIN) {
        cout << "The second largest element is: " << secondLargest << endl;
    } else {
        cout << "There is no second largest element." << endl;
    }
    return 0;
}