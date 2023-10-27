#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> prefixArray(vector<int> &arr, int n) {
    // code here
    vector<int> preArr;
    preArr.push_back(arr[0]);
    for(int i = 0; i < n-1; i++) {
        preArr.push_back(preArr[i] + arr[i+1]);
    }
    return preArr;
}

int main() {
    vector<int> arr = {4, 3, 7, 2};
    int n = arr.size();
    vector<int> preArr = prefixArray(arr, n);
    for(int i = 0; i < n; i++) {
        cout << preArr[i] << " ";
    }
    return 0;
}