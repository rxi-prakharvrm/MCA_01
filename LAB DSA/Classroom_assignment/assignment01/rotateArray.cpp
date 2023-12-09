#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int rotate) {
    for(int i = 0; i < rotate; i++) {
        int temp = arr[n-1]; // store last element of arr

        for(int j = n-1; j >= 0; j--)
            arr[j] = arr[j-1]; // replace all successive places with the current one

        arr[0] = temp; // store the last element at the 0th index
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int rotate = 2;

    rotateArray(arr, n, rotate);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}