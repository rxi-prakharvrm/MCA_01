#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void occurrences(vector<int> &arr, int n) {
    // decrement 1 from each element of the array
    for(int i = 0; i < arr.size(); i++) {
        arr[i]--;
    }

    // storing the number and occurrence of that number in the same variable
    for(int i = 0; i < arr.size(); i++) {
        int pos = arr[i] % n;
        arr[pos] += n;
    }

    // filter out the occurrences
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = arr[i] / n;
    }

    // Printing the occurrences
    for(int i = 0; i < arr.size(); i++) {
        cout << "Occurrence of " << i + 1 << " is: " << arr[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 3, 7, 4, 2, 3, 7};
    int n = 10;
    occurrences(arr, n);
    return 0;
}