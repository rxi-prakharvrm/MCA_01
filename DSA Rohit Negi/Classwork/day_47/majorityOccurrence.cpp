#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int occurrences(vector<int> &arr, int n) {
    int count = 0;
    int candidate;

    for(int i = 1; i < n; i++) {
        if(count == 0) {
            count = 1;
            candidate = arr[i];
        } else {
            if(candidate == arr[i]) {
                count++;
            } else {
                count--;
            }
        }
    }

    cout << candidate << " " << count << endl;

    return (candidate > n/2) ? candidate : -1;
}

int main() {
    vector<int> arr = {3};
    int n = arr.size();
    cout << occurrences(arr, n) << endl;
    return 0;
}