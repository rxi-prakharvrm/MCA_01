#include <iostream>
using namespace std;

void pattern2() {
    int row = 5;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= row; j++) {
            if(i == 1 || i == row || j == 1 || j == row) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    pattern2();
    return 0;
}