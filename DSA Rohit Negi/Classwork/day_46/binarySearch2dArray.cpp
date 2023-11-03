#include <iostream>
using namespace std;

// O(log N)
bool binarySearch(int arr[4][5], int row, int col, int target) {
    int start = 0;
    int end = row * col - 1;
    int mid, rowIndex, colIndex;

    while(start <= end) {
        mid = start + (end - start) / 2;
        rowIndex = mid / col;
        colIndex = mid % col;

        if(arr[rowIndex][colIndex] == target) {
            return 1;
        }

        if(arr[rowIndex][colIndex] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}


// O(N + log(M))
// bool binarySearch(int arr[4][5], int row, int col, int target) {
//     for(int i = 0; i < row; i++) {
//         if(target >= arr[i][0] && target <= arr[i][col-1]) {
//             int start = 0;
//             int end = col - 1;
//             int mid;

//             while(start <= end) {
//                 mid = start + (end - start) / 2;
//                 if(arr[i][mid] == target) {
//                     return 1;
//                 }

//                 if(arr[i][mid] > target) {
//                     end = mid - 1;
//                 } else {
//                     start = mid + 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }

int main() {
    int arr[4][5] = {
                     {10, 11, 15, 17, 19},
                     {20, 24, 30, 40, 50},
                     {60, 70, 76, 80, 82},
                     {90, 91, 93, 97, 99}
                    };
    int row = 4;
    int col = 5;
    int target;

    cout << "Enter the number you want to search: ";
    cin >> target;

    cout << binarySearch(arr, row, col, target) << endl;
    return 0;
}   