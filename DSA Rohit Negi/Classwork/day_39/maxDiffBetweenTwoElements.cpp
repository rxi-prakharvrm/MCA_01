#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
// int maxDiff(vector<int> &arr, int n) {
//     int ans = INT_MIN;

//     for(int i = 0; i < n-1; i++) {
//         for(int j = i+1; j < n; j++) {
//             ans = max(ans, arr[j] - arr[i]);
//         }
//     }

//     return ans;
// }

// O(n)
int maxDiff(vector<int> &arr, int n) {
    int ans = INT_MIN;
    int suffix = arr[n-1];

    for(int i = n-2; i >= 0; i--) {
        ans = max(ans, suffix-arr[i]);
        suffix = max(suffix, arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {9, 5, 8, 12, 2, 3, 7, 4};
    int n = arr.size();
    int ans = maxDiff(arr, n);
    cout << "Maximum difference between elements of the array: " << ans << endl;
    return 0;
}