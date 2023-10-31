#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[4][3] = {{1, 2, 3}, {8, 3, 2}, {3, 6, 3}, {2, 7, 1}};
    int row = 4, col = 3;
    int rowSum[3];

    for(int i = 0; i < row; i++) {
        int total = 0;
        for(int j = 0; j < col; j++) {
            total += arr[i][j];
        }
        rowSum[i] = total;
    }

    int maxSum = INT_MIN;
    for(int i = 0; i < row; i++) {
        if(rowSum[i] > maxSum) {
            maxSum = rowSum[i];
        }
    }
    
    cout << maxSum << endl;
    return 0;
}