#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void segregate(vector<int> &v, int n) {
    int start = 0;
    int end = n-1;

    while(start < end) {
        if(v[start] == 0) start++;
        else {
            if(v[start] > v[end]) {
                swap(v[start], v[end]);
                start++;
                end--;
            } else {
                end--;
            }
        }
    }
}

int main() {
    vector<int> v = {0, 0, 0, 1, 1, 0};
    segregate(v, v.size());
    cout << "Segregated array is: " << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}