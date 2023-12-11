#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void product(vector<int> arr, int n, int &ans) {
    if(n == 0) return;
    ans *= arr[n-1];
    product(arr, n-1, ans);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int ans = 1;
    product(arr, arr.size(), ans);
    cout << ans << endl;
    return 0;
}