#include <iostream>
#include <math.h>
using namespace std;

/*

*
***
*****
*******
*****
***
*

*/

void pattern4() {
    int row = 7;
    for(int i = -3; i <= floor(row/2); i++) {
        for(int j = 0; j < abs(i); j++) {
            cout << " ";
        }
        for(int k = 0; k < row - (2*abs(i)); k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    pattern4();
    return 0;
}