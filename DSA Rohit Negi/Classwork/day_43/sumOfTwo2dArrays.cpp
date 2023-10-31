#include <iostream>
using namespace std;

int main() {
    int row = 2, col = 3;
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[2][3] = {{1, 1, 1}, {1, 1, 1}};
    int sum[2][3];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}