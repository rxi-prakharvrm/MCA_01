#include <iostream>
using namespace std;

int sumOfElementsInArray(int arr[], int size) {
    if(size == 0) return 0;
    return arr[0] + sumOfElementsInArray(arr+1, size-1);
}

int main() {
    // int arr[] {1, 3, 6, 2, 4};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = sumOfElementsInArray(arr, size);
    cout << result << endl;
    return 0;
}