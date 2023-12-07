#include <iostream>
using namespace std;

void pattern3() {
    int row = 4;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    pattern3();
    return 0;
}