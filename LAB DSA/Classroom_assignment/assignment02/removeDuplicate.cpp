#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                arr[i] = -1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] == -1) {
            arr.erase(arr.begin()+i);
            i--;
        }
    }

    return arr;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    vector<int> res = removeDuplicates(arr, n);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
