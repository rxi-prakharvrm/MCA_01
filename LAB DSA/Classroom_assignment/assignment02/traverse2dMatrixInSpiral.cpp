#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int left = 0, right = v[0].size()-1, top = 0, bottom = v.size()-1;
    while(left <= right and top <= bottom) {
        for(int i = left; i <= right; i++) {
            cout << v[top][i] << " ";
        }
        top++;

        for(int i = top; i <= bottom; i++) {
            cout << v[i][right] << " ";
        }
        right--;

        for(int i = right; i >= left; i--) {
            cout << v[bottom][i] << " ";
        }
        bottom--;

        for(int i = bottom; i >= top; i--) {
            cout << v[i][left] << " ";
        }
        left++;
    }
    return 0;
}