#include <iostream>
using namespace std;

void arrayMultiplication(int arr1[][3], int arr2[][3], int mul[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int temp = 0;
            for(int k = 0; k < 3; k++) {
                temp +=arr1[i][k]*arr2[k][j];
            }
            mul[i][j] = temp;
        }
    }
}

int main() {
    int arr1[3][3] {{1, 2, 3}, {2, 5, 2}, {6, 2, 3}};
    int arr2[3][3] {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int mul[3][3];
    arrayMultiplication(arr1, arr2, mul);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}