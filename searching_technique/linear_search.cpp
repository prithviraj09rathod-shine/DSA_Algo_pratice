#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int target){
    int n = arr.size();
    
    // Iterate linearly through the array
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 1, 5}; 
    int target = 7;
    //index of 7 is 3 that we need to find it
    int index = search(arr, target);
    cout<<index<<endl;
    return 0;
}
