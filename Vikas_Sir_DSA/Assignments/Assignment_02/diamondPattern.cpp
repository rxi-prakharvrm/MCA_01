#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of row: ";
    cin >> n;

    for(int row = -n/2; row <= n/2; row++) {
        for(int col = 1; col <= abs(row); col++) {
            cout << "  ";
        }
        for(int col = 1; col <= n-2*abs(row); col++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}