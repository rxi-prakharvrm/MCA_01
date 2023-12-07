#include <iostream>
using namespace std;

int evenOrOdd(int num) {
    if(num == 0) return 0;
    evenOrOdd(num-1);
    if(num%2 == 0) cout << num << " ";
}

int main() {
    evenOrOdd(10);
    return 0;
}