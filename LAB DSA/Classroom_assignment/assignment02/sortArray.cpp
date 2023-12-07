#include <iostream>
using namespace std;

void sortArray(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        cout << "Enter element: " << i+1 << ": ";
        cin >> arr[i];
    }

    sortArray(arr, size);
    return 0;
}