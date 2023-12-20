#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for(int row = -n/2; row <= n/2; row++) {
        for(int col = 1; col <= ceil(n/2.0)-abs(row); col++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}