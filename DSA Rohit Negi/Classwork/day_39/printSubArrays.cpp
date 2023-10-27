#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ***************************** WRONG ************************************

// void prefixSubArr(vector<int> &arr, int n) {
//     vector<int> subArr;
//     while(n > 0) {
//         for(int i = 0; i < n; i++) {
//             cout << "[" << arr[i] << "]";
//         }
//         cout << endl;
//         n--;
//     }
// }

int main() {
    vector<int> arr = {2, 4, 7, 3};
    int n = arr.size();
    // prefixSubArr(arr, n);
    return 0;
}