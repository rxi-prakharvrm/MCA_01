#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void waveForm(vector<vector<int>> &matrix, int row, int col) {
    for(int i = 0; i < col; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < row; j++) {
                cout << matrix[j][i] << " ";
            }
        } else {
            for(int j = row-1; j >= 0; j--) {
                cout << matrix[j][i] << " ";
            }
        }
    }
}

int main() {    
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3, col = 3;
    // int row, col;
    // cout << "Enter rows and columns: ";
    // cin >> row >> col;

    // vector<vector<int>> matrix(row, vector<int> (col, 1));
    // int value;

    // for(int i = 0; i < row; i++) {
    //     for(int j = 0; j < col; j++) {
    //         cin >> value;
    //         matrix[i][j] = value;
    //     }
    // }

    waveForm(matrix, row, col);

    return 0;
}