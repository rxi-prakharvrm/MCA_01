#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix, int row, int col) {
    int temp;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {    
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int row = matrix.size(), col = matrix[0].size();

    transpose(matrix, row, col);

    return 0;
}