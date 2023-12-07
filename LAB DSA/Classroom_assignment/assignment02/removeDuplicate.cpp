#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int *arr, int &size) {

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *p = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> p[i];
    }
    removeDuplicates(p, size);
    return 0;
}