#include <iostream>
using namespace std;

// row wise traversal of the matrix
void traverse(int mat[3][3], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3;
    int col = 3;

    traverse(mat, row, col);
    return 0;
}