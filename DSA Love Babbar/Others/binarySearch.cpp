#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key) {
    if(start > end) return false;

    int mid = start + (end - start) / 2;

    if(arr[mid] == key) {
        return true;
    }

    if (key < arr[mid]) {
        return binarySearch(arr, start, mid-1, key);
    } else {
        return binarySearch(arr, mid+1, end, key);
    }
}

int main() {
    int arr[] {3, 6, 1, 7, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 7;
    bool result = binarySearch(arr, 0, size-1, key);
    (result) ? cout << "Found!" << endl : cout << "Not Found!" << endl;
    return 0;
}