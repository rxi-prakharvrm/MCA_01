#include <iostream>
using namespace std;

void pattern1() {
    for(int row = 1; row <= 5; row++) {
        for(int col = 5; col > row; col--) {
            cout << " ";
        }
        for(int col = 1; col <= 2*row-1; col++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    pattern1();
    return 0;
}