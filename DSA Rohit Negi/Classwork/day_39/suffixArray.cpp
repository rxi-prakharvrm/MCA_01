#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> suffixArr(vector<int> &arr, int n) {
    // code here
    vector<int> suffArr;
    suffArr.push_back(arr[n-1]);
    for(int i = 0; i < n-1; i++) {
        suffArr.push_back(suffArr[i] + arr[n-i-2]);
    }
    return suffArr;
}

int main() {
    vector<int> arr = {4, 3, 7, 2};
    int n = arr.size();
    vector<int> suffArr = suffixArr(arr, n);
    for(int i = 0; i < n; i++) {
        cout << suffArr[i] << " ";
    }
    return 0;
}