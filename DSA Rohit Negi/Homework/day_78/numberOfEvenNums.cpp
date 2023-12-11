#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countEvenElements(vector<int> arr, int n, int &countEven) {
    if(n == 0) return;
    if(arr[n-1] % 2 == 0) {
        countEven++;
    }
    countEvenElements(arr, n-1, countEven);
}

int main() {
    vector<int> arr = {2, 6, 3, 10, 9, 5, 2, 16};
    int countEven = 0;
    countEvenElements(arr, arr.size(), countEven);
    cout << countEven << endl;
    return 0;
}