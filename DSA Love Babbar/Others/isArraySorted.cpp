#include <iostream>
using namespace std;

int isSorted(int arr[], int size) {
    if(size == 1 || size == 0) return true;
    if(arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted(arr+1, size-1);
    }
}

int main() {
    // int arr[] {1, 2, 5, 8, 9, 11};
    int arr[] {5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    (isSorted(arr, size)) ? cout << "Sorted!" << endl : cout << "Not Sorted!" << endl;
    return 0;
}