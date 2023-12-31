#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // create a 2d array using vector
    // number of rows = cols
    // number of columns = rows
    vector<vector<int>> transMatrix(cols, vector<int>(rows, 0));

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            transMatrix[j][i] = matrix[i][j];
        }
    }

    matrix = transMatrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}};
    transpose(matrix);

    cout << "Trasposed matrix: " << endl;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}