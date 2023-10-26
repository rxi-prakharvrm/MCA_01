#include <iostream>
using namespace std;

int isFound(int arr[], int size, int element) {
    if(size == 0) return false;
    if(arr[0] == element) return true;
    return isFound(arr+1, size-1, element);
}

int main() {
    int arr[] {1, 2, 5, 9, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int element;
    cout << "Which element do you wanna search in the given array?" << endl;
    cin >> element;
    bool result = isFound(arr, size, element);
    (result)? cout << element << " is Found!" << endl : cout << element << " is Not Found!" << endl;
    return 0;
}