#include <iostream>
using namespace std;

bool searchElement(int arr[][3], int x, int row, int col) {

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] == x) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int row = 2;
    int col = 3;
    int x = 5;
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << searchElement(arr, x, row, col) << endl;
    return 0;
}