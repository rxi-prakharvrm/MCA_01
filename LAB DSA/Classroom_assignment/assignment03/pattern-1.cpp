#include <iostream>
using namespace std;

void pattern1() {
    int row = 5;
    for(int i = 1; i <= row; i++) {
        for(int j = 5; j > i; j--) {
            cout << " ";
        }
        for(int j = 1; j <= 2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    pattern1();
    return 0;
}