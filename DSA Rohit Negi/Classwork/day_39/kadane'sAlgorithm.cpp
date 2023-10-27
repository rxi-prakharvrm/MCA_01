#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kadaneAlgo(vector<int> &arr, int n) {
    int maxElement = INT_MIN;
    int prefix = 0;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        maxElement = max(maxElement, prefix);
        
        if(prefix < 0) {
            prefix = 0;
        }
    }

    return maxElement;
}

int main() {
    vector<int> arr = {3, 4, -5, 8, -12, 7, 6, -2};
    int n = arr.size();
    int ans = kadaneAlgo(arr, n);
    cout << "Maximum sum of sub array is: " << ans << endl;
    return 0;
}