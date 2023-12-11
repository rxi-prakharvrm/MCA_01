#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void product(vector<int> arr, int n, int &ans) {
//     if(n == 0) return;
//     ans *= arr[n-1];
//     product(arr, n-1, ans);
// }

int product(vector<int> arr, int n) {
    if(n == 0) return 1;
    return arr[n-1] * product(arr, n-1);
}

int main() {
    vector<int> arr = {10, 2, 3, 4, 5};
    int ans = product(arr, arr.size());
    cout << ans << endl;
    return 0;
}