#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class T>
int tripletSum(vector<T> &arr, int n, T target) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Calculating triplet sum
    for(int i = 0; i < n-2; i++) {
        int ans = target - arr[i];
        int start = i+1;
        int end = n-1;

        while(start < end) {
            if(arr[start] + arr[end] == ans) {
                return 1;
            } else if(arr[start] + arr[end] > ans){
                end--;
            } else {
                start++;
            }
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {4, 2, 6, 1, 0, 7};
    int n = arr.size();
    int target = 10;
    cout << tripletSum(arr, n, target) << endl;
    return 0;
}