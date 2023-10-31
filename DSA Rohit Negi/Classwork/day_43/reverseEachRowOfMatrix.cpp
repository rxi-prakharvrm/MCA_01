#include <iostream>
using namespace std;

void reverseEachRow(int arr[][4], int row, int col) {
    int i = 0;
    while(i < row) {
        int s = 0;
        int e = col-1;
        while(s < e) {
            swap(arr[i][s], arr[i][e]);
            s++;
            e--;
        }
        i++;
    }
}

void printReversed2dArray(int arr[][4], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {    
    int arr[4][4] = {
                     {1, 2, 3, 4},
                     {6, 2, 0, 6},
                     {6, 9, 3, 6},
                     {1, 1, 6, 7}
                    };
    int row = 4, col = 4;
    reverseEachRow(arr, row, col);
    printReversed2dArray(arr, row, col);
    return 0;
}