#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

void maxElement(vector<int> arr, int n, int &ans) {
    if(n == -1) return;
    if(arr[n-1] > ans) {
        ans = arr[n-1];
        maxElement(arr, n-1, ans);
    }
}

int main() {
    vector<int> arr = {2, 6, 3, 10, 9, 5};
    int ans = INT_MIN;
    maxElement(arr, arr.size(), ans);
    cout << ans << endl;
    return 0;
}