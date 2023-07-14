#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 2, 0, 4, 7, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i, j, temp = 0;
    for(i = 0; i < size-1; i++) {
        for(j = i+1; j < size; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
