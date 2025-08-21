// C++ program to find binary 
// representation of a given number
#include <iostream>
using namespace std;

string getBinaryRep(int n) {

    // Create a 32 length string 
    // of 0's 
    string ans = "";
    for (int i=0; i<32; i++) ans += '0';
    
    for (int i=0; i<32; i++) {
        
        // Set 1 f rightmost bit is set 
        if (n%2 == 1) ans[31 - i] = '1';
        
        // Right shift bits using divison 
        // operator 
        n = n / 2;
    }
    
    return ans;
}

int main() {
    int n = 2;
    cout << getBinaryRep(n);

    return 0;
}
