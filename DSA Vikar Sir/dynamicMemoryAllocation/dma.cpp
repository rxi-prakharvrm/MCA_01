#include <iostream>
using namespace std;

int main() {
    int* ptr;

    // Memory allocation using malloc
    // ptr = (int *) malloc (10*sizeof(int));

    // Memory allocation using calloc
    ptr = (int *) calloc (10, sizeof(int));

    // Assigning values to the dynamically created array
    for(int i = 0; i < 10; i++) {
        ptr[i] = i+1;
    }

    // Increasing the size of the dynamically created memory
    ptr = (int *) realloc (ptr, 20*sizeof(int));
    for(int i = 10; i < 20; i++) {
        ptr[i] = i + 1;
    }

    // Printing the values of the dynamically create array
    for(int i = 0; i < 20; i++) {
        cout << ptr[i] << " ";
    }

    return 0;
}