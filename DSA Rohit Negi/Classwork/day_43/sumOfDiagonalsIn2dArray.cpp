#include <iostream>
using namespace std;

// void diagonalSum(int arr[][4], int row, int col) {
//     int sumOfPrincipalDiagonal = 0;
//     int sumOfNormalDiagonal = 0;

//     for(int i = 0; i < row; i++) {
//         for(int j = 0; j < col; j++) {
//             if(i == j) {
//                 sumOfPrincipalDiagonal += arr[i][j];
//             }

//             if(i+j == row-1) {
//                 sumOfNormalDiagonal += arr[i][j];
//             }
//         }
//     }
//     cout << "Sum of principal diagonal = " << sumOfPrincipalDiagonal << endl;
//     cout << "Sum of normal diagonal = " << sumOfNormalDiagonal << endl;
// }

void diagonalSum(int arr[][4], int row, int col) {
    int sumOfPrincipalDiagonal = 0, sumOfNormalDiagonal = 0;
    int i = 0;

    // Sum of principal diagonal
    while(i < row) {
        sumOfPrincipalDiagonal += arr[i][i];
        i++;
    }

    // Sum of normal diagonal
    i = 0;
    int j = col-1;
    while(j >= 0) {
        sumOfNormalDiagonal += arr[i][j];
        i++;
        j--;
    }

    cout << "Sum of principal diagonal = " << sumOfPrincipalDiagonal << endl;
    cout << "Sum of normal diagonal = " << sumOfNormalDiagonal << endl;
}

int main() {
    int arr[4][4] = {
                     {1, 2, 3, 4},
                     {6, 2, 0, 6},
                     {6, 9, 3, 6},
                     {1, 1, 6, 7}
                    };
    int row = 4, col = 4;
    diagonalSum(arr, row, col);
    return 0;
}