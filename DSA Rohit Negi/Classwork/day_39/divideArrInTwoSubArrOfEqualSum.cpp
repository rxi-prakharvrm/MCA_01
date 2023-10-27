#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(n^2)
// int divideArr(vector<int> &arr, int n) {
//         int firstPartSum = 0;
//         int secondPartSum = 0;
//     for(int i = 0; i < n-1; i++) {
//         for(int j = 0; j <= i; j++) {
//             firstPartSum += arr[j];
//         }
//         for(int j = i+1; j < n; j++) {
//             secondPartSum += arr[j];
//         }
//         if(firstPartSum == secondPartSum) {
//             return 1;
//         }
//     }
//     return 0;
// }

// O(n)
int divideArr(vector<int> &arr, int n) {
    int totalSum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int prefix = 0;
    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        ans = totalSum - prefix;

        if(ans == prefix) {
            return 1;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {1, 4, 3, 2, -7, -3};
    int n = arr.size();
    cout << divideArr(arr, n);
    return 0;
}